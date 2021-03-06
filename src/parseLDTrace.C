#include <stdio.h>
#include <string.h>
#include "compute_sha1.h"
#include "link_submission.h"
#include "xalt_fgets_alloc.h"
#include "xalt_config.h"

ArgV            argV;

void addPath2Set(std::string& path, Set& set)
{
  char* my_realpath = canonicalize_file_name(path.c_str());
  if (my_realpath)
    {
      path.assign(my_realpath);
      set.insert(path);
      free(my_realpath);
    }
}

void parseLDTrace(const char* xaltobj, const char* linkfileFn, std::vector<Libpair>& libA)
{
  std::string path;
  char* buf = NULL;
  size_t sz = 0;
  
  Set set;

  FILE* fp = fopen(linkfileFn,"r");

  while(xalt_fgets_alloc(fp, &buf, &sz))
    {
      // Remove lines with ':'
      if (strchr(buf,':'))
        continue;

      // Remove the line with the xalt.o file
      if (strstr(buf, xaltobj))
        continue;

      // Remove any lines that start with /tmp/
      // This will ignore files like /tmp/ccT33qQt.o
      char * p = strstr(buf,"/tmp/");
      if (buf == p)
        continue;
      
      // Ignore all *.o files
      int len = strlen(buf);
      if (len > 2 && strstr(&buf[len-3],".o\n"))
        continue;

      char * start = strchr(buf,'(');
      if (start)
        {
          // Capture the library name in the parens:
          //    -lgcc_s (/usr/lib/gcc/x86_64-linux-gnu/4.8/libgcc_s.so)
          // or 
          //    (/usr/lib/x86_64-linux-gnu/libc_nonshared.a)elf-init.oS
          //
          // Note that we are going to ignore
          //    /usr/lib/x86_64-linux-gnu/libc_nonshared.a(elf-init.oS)

          char * p     = strchr(start+1,')');
          if ( start == NULL || p == NULL)
            continue;

          path.assign(start+1, p);
          addPath2Set(path, set);
          continue;
        }

      // Save everything else (and get rid of the trailing newline!)
      path.assign(buf, len - 1);
      addPath2Set(path, set);
    }

  free(buf); sz = 0; buf = NULL;

  for(auto const & it : set)
    argV.push_back(Arg(it));

  long fnSzG = argV.size();

  compute_sha1_master(fnSzG);  // compute sha1sum for all files.

  for (long i = 0; i < fnSzG; ++i)
    {
      Libpair libpair(argV[i].fn, argV[i].sha1);
      libA.push_back(libpair);
    }
}

void readFunctionList(const char* fn, Set& funcSet)
{
  char*  buf = NULL;
  size_t sz  = 0;
  
  FILE* fp = fopen(fn,"r");
  std::string funcName;

  // /tmp/ccCZTucS.o: In function `main':
  // /home/mclay/w/xalt/rt/mpi_hello_world.c:10: undefined reference to `MPI_Comm_rank'
  // /home/mclay/w/xalt/rt/mpi_hello_world.c:11: undefined reference to `MPI_Comm_size'
  // /home/mclay/w/xalt/rt/mpi_hello_world.c:16: undefined reference to `MPI_Finalize'


  const char * needle = "undefined reference to ";
  int   len_needle    = strlen(needle);

  while(xalt_fgets_alloc(fp, &buf, &sz))
    {
      // skip all lines that do not have "undefine references to "
      char* start = strstr(buf,needle);
      
      if (start == NULL)
        continue;

      start += len_needle;

      if (*start == '`')
        start++;
      char*  p   = strchr(start,'\'');
      size_t len = (p) ? p - start: strlen(start);
      funcName.assign(start, len);
      funcSet.insert(funcName);
    }
  free(buf); sz  = 0; buf = NULL;
}
