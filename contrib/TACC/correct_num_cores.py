#!/usr/bin/env python
# -*- python -*-

from __future__ import print_function
import os, sys, re, time, datetime, argparse, ConfigParser, base64, MySQLdb
#from xalt_util import *

class CmdLineOptions(object):
  """ Command line Options class """

  def __init__(self):
    """ Empty Ctor """
    pass
  
  def execute(self):
    """ Specify command line arguments and parse the command line"""
    parser = argparse.ArgumentParser()
    parser.add_argument("--dryrun",       dest='dryrun',       action="store_true",  default = None,          help="dryrun")
    parser.add_argument("--dbname",       dest='dbname',       action="store",       default = "xalt",        help="db name")
    args = parser.parse_args()
    return args


def dbConfigFn(dbname):
  """
  Build config file name from dbname.
  @param dbname: db name
  """
  return dbname + "_db.conf"


def correct_num_cores(cursor, acctT):
  """
  This routine replaces the account name when it is unknown and it computes the run_time for the job.
  There are two conditions to handle:
     a) The job_id can be unknown.  This is probably due to the fact that the users script as wiped
        all environment variables including the env var that has the job_id.
     b) The accounting record is only written when the job completes.  However XALT writes a record
        at the beginning of the job. So an XALT record can exist where there is no accounting record.
     
  When both the accounting record exists and the XALT record exists, this routine gets a charge account
  (chargeAcct) from the accounting record and replaces the XALT account column when it differs.
  Similarly if the end_time from XALT is 0.0 then the run_time is computed and replaced.

  The XALT end_time and run_time are 0.0 on the initial record.  So if the job times out then the end
  XALT record is not written.  This routine writes the run_time but doesn't set end_time.  This way jobs
  that timed out can be found in the XALT db.
  @param cursor:   database accessor object
  @param acctT:    account record
  """

  query = "select job_id from xalt_run where date >= '2015-06-05' and date < '2015-06-06'"
  cursor.execute(query)

  jobA = cursor.fetchall()

  n_update = 0
  for job_id in jobA:
    entryT = acct.get(job_id)
    if (job_id == "unknown" or entryT == None):
      continue

    query = "select run_id, run_time, num_cores from xalt_run where job_id = %s"
    cursor.execute(query, [job_id])
    SUs    = 0.0
    totalT = 0.0
    for run_id, run_time, num_cores in cursor:
      run_time  = float(run_time)/3600.0
      num_cores = float(num_cores)
      SUs      += run_time*num_cores
      totalT   += run_time

    acctSUs = (entryT['end_time'] - entryT['start_time'])*entryT['num_cores']/3600.0

    ratio = SUs/acctSUs
    if (ratio > 1.10):
      n_update  += cursor.rowcount
      num_cores  = min(1.0, int(acctSUs/totalT))

      print("For job_id: %s, new cores: %d, acctSUs: %.2f, SUs: %.2f" % (job_id, num_cores, acctSUs, totalT*num_cores))



      #cursor.execute("START TRANSACTION")
      #query = "update xalt_run set num_cores = %s where job_id = %s"
      #cursor.execute(query, (num_cores, job_id))
      #cursor.execute("COMMIT")

    


      

  print("updated",n_update,"records")
  cursor.execute("COMMIT")

def read_tacc_acct_records():
  """
   0: Job ID ($JOBID)
   1: User ID ($UID) 
   2: Project ID ($ACCOUNT) 
   3: Junk ($BATCH) 
   4: Start time ($START) 
   5: End time ($END) 
   6: Time job entered in queue ($SUBMIT) 
   7: SLURM partition ($PARTITION) 
   8: Requested Time ($LIMIT) 
   9: Job name ($JOBNAME)
  10: Job completion status ($JOBSTATE) 
  11: Nodes ($NODECNT) 
  12: Cores ($PROCS)
  """
  acctT    = {}
  endtimeT = {}

  fn = "tacc_jobs_completed"
  f = open(fn,"r")
  for line in f:
    fieldA          = line.split(":")
    if (len(fieldA) < 6):
      continue
    jobId           = fieldA[0]
    chargeAcct      = fieldA[2]
    end_time        = fieldA[5]
    num_nodes       = fieldA[11]
    num_cores       = fieldA[12]
    acctT[jobId]    = { 'chargeAcct' : chargeAcct,
                        'end_time'   : end_time,
                        'num_nodes'  : num_node,
                        'num_cores'  : num_cores
                      }
  f.close()
  return acctT



def main():
  args     = CmdLineOptions().execute()
  config   = ConfigParser.ConfigParser()     
  configFn = dbConfigFn(args.dbname)
  config.read(configFn)

  conn = MySQLdb.connect \
         (config.get("MYSQL","HOST"), \
          config.get("MYSQL","USER"), \
          base64.b64decode(config.get("MYSQL","PASSWD")), \
          config.get("MYSQL","DB"))
  cursor = conn.cursor()

  XALT_ETC_DIR = os.environ.get("XALT_ETC_DIR","./")
  acctT = read_tacc_acct_records()

  correct_num_cores(cursor, acctT)
  

if ( __name__ == '__main__'): main()
  


