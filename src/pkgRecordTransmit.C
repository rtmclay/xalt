#include "xalt_fgets_alloc.h"
#include "run_submission.h"
#include "xalt_tmpdir.h"
#include "xalt_utils.h"
#include "transmit.h"
#include <dirent.h>
#include <fnmatch.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <unistd.h>

void pkgRecordTransmit(Options& options, const char* transmission)
{
  char * xalt_tmpdir = create_xalt_tmpdir_str(options.uuid().c_str());
  DIR*   dirp        = opendir(xalt_tmpdir);
  if (dirp == NULL)
    {
      free(xalt_tmpdir);
      return;
    }

  char* c_home = getenv("HOME");
  char* c_user = getenv("USER");
  if (c_home == NULL || c_user == NULL )
    return;

  int         ulen = 12;
  std::string home = c_home;
  std::string user = c_user;
  std::string xaltDir;

  build_xaltDir(xaltDir, "pkg", user, home, transmission);

  struct dirent* dp;
  while ( (dp = readdir(dirp)) != NULL)
    {
      if (fnmatch("pkg.*.json", dp->d_name, 0) == 0)
        {
          char*       buf     = NULL;
          size_t      sz      = 0;
          std::string jsonStr = "";
          std::string fullName(xalt_tmpdir);
          
          fullName.append("/");
          fullName.append(dp->d_name);
          FILE* fp = fopen(fullName.c_str(), "r");
          if (fp)
            {
              while( xalt_fgets_alloc(fp, &buf, &sz))
                jsonStr += buf;
              free(buf);
              sz = 0; buf = NULL;

              // build resultFn from dp->d_name
              std::string resultFn(xaltDir);
              resultFn.append(dp->d_name);
              char * my_resultFn = strdup(resultFn.c_str());
                
              // build key from dp->d_name;
              //                                                                       0123456789 1234567
              //pkg.rios.2018_11_06_16_14_13_7992.d20188d7-bbbb-4b91-9f5c-80672045c270.3ee8e5affda9.json
              char * key = NULL;
              int my_len = strlen(dp->d_name);
              asprintf(&key, "pkg_%s_%.*s",options.uuid().c_str(), ulen, &dp->d_name[my_len - 17]);

              // transmit jsonStr
              
              transmit(transmission, jsonStr.c_str(), "pkg", key, options.syshost().c_str(), my_resultFn);
              free(key);
              free(my_resultFn);
              unlink(fullName.c_str());
            }
          fclose(fp);
        }
    }
  rmdir(xalt_tmpdir);
  free(xalt_tmpdir);
}