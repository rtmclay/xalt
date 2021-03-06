#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <time.h>
#include <strings.h>
#include <string.h>

#include "xalt_quotestring.h"
#include "epoch.h"
#include "walkProcessTree.h"
#include "Options.h"
#include "Json.h"
#include "xalt_utils.h"
#include "xalt_config.h"
#include "transmit.h"
#include "buildRmapT.h"
#include "run_submission.h"
#include "xalt_utils.h"
#include "build_uuid.h"

int main(int argc, char* argv[], char* env[])
{
  char *      p_dbg        = getenv("XALT_TRACING");
  int         xalt_tracing = (p_dbg && ( strcmp(p_dbg,"yes") == 0 || strcmp(p_dbg,"run") == 0));

  Options     options(argc, argv);
  double      t0, t1;
  double      t_maps, t_sha1;
  DTable      measureT;
  bool        end_record = (options.endTime() > 0.0);
  char        uuid_str[37];
  
  
  
  const char* suffix = end_record ? ".zzz" : ".aaa";
  DEBUG1(stderr,"\n  xalt_run_submission(%s) {\n",suffix);
  
  if (options.buildUUID())
    {
      build_uuid(&uuid_str[0]);
      DEBUG1(stderr,"    building UUID: %s\n",uuid_str);
    }
  else
    {
      strcpy(&uuid_str[0], options.uuid().c_str());
      DEBUG1(stderr,"    using UUID: %s\n",uuid_str);
    }

  t0 = epoch();
  t1 = t0;
  std::vector<ProcessTree> ptA;
  walkProcessTree(options.ppid(), ptA);
  measureT["04_WalkProcTree_"] = epoch() - t1;
    
  //*********************************************************************
  // Build the env table:
  t1 = epoch();
  Table envT;
  buildEnvT(options, env, envT);
  DEBUG0(stderr,"    Built envT\n");
  measureT["03_BuildEnvT____"] = epoch() - t1;

  //*********************************************************************
  // Extract the xalt record stored in the executable (possibly)
  t1 = epoch();
  Table recordT;
  std::string watermark = options.watermark();
  if (watermark == "FALSE")
    extractXALTRecordString(options.exec(), watermark);
  buildXALTRecordT(watermark, recordT);
  DEBUG0(stderr,"    Extracted recordT from executable\n");
  measureT["05_ExtractXALTR_"] = epoch() - t1;

  //*********************************************************************
  // Build userT
  t1 = epoch();
  Table  userT;
  DTable userDT;

  buildUserT(options, uuid_str, envT, userT, userDT);
  if ( ! recordT.empty())
    userDT["Build_Epoch"] = strtod(recordT["Build_Epoch"].c_str(),(char **) NULL);
  DEBUG1(stderr,"    Built userT, userDT, scheduler: %s\n", userT["scheduler"].c_str());
  measureT["01_BuildUserT___"] = epoch() - t1;

  //*********************************************************************
  // Filter envT 
  t1 = epoch();
  filterEnvT(env, envT);
  DEBUG0(stderr,"    Filter envT\n");
  measureT["03_BuildEnvT____"] += epoch() - t1;
  

  //*********************************************************************
  // Take sha1sum of the executable
  t1 = epoch();
  std::string sha1_exec;
  compute_sha1(options.exec(), sha1_exec);

  measureT["02_Sha1_exec____"] = epoch() - t1;
  
  //*********************************************************************
  // Parse the output of ldd for this executable (start record only)
  std::vector<Libpair> libA;
  parseProcMaps(options.pid(), libA, t_maps, t_sha1);
  DEBUG0(stderr,"    Parsed ProcMaps\n");

  measureT["06_ParseProcMaps"] = t_maps;
  measureT["06_SO_sha1_comp_"] = t_sha1;
  
  const char * transmission = getenv("XALT_TRANSMISSION_STYLE");
  if (transmission == NULL)
    transmission = TRANSMISSION;
  
  DEBUG1(stderr,"    Using XALT_TRANSMISSION_STYLE: %s\n",transmission);

  //*********************************************************************
  // If here then we need the json string.  So build it!
  measureT["07____total_____"] = epoch() - t0;

  Json json;
  DEBUG1(stderr,"    cmdlineA: %s\n",options.userCmdLine().c_str());
  json.add_json_string("cmdlineA",options.userCmdLine());
  json.add("ptA", ptA);
  json.add("envT",envT);
  json.add("userT",userT);
  json.add("userDT",userDT);
  json.add("xaltLinkT",recordT);
  json.add("hash_id",sha1_exec);
  json.add("libA",libA);
  json.add("XALT_measureT",measureT);
  json.fini();

  DEBUG0(stderr,"    Built json string\n");

  char*       c_resultFn  = NULL;
  char*       c_resultDir = NULL;  
  std::string jsonStr     = json.result();
  std::string fn;


  std::string key   = (end_record) ? "run_fini_" : "run_strt_";
  key.append(uuid_str);

  if (strcasecmp(transmission, "file") == 0 || strcasecmp(transmission, "file_separate_dirs") == 0)
    {
      std::string resultDir, resultFn;
      build_resultDir(resultDir, "run", transmission, uuid_str);


      build_resultFn(resultFn, options.startTime(), options.syshost().c_str(), uuid_str,
                     "run", suffix);
      c_resultFn  = strdup(resultFn.c_str());
      c_resultDir = strdup(resultDir.c_str());
    }

  transmit(transmission, jsonStr.c_str(), "run", key.c_str(), options.syshost().c_str(), c_resultDir, c_resultFn);
  xalt_quotestring_free();
  if (c_resultFn)
    {
      free(c_resultFn);
      free(c_resultDir);
    }

  //*********************************************************************
  // Transmit Pkg records if any
  if (options.kind() == "PKGS")
    pkgRecordTransmit(uuid_str, options.syshost().c_str(), transmission);


  //*********************************************************************
  // Send uuid back to xalt_initialize if asked for.
  if (options.returnUUID())
    fprintf(stdout,"%s\n", uuid_str);

  DEBUG0(stderr,"  }\n\n");
  if (xalt_tracing)
    fflush(stderr);
  return 0;
}
