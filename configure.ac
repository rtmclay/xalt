AC_INIT(Makefile.in)
AC_CONFIG_HEADERS(src/__build__/xalt_header.h:src/xalt_header.h.in)
AC_PROG_CC
AC_PREFIX_DEFAULT(/usr/local)
dnl AC_CONFIG_SUBDIRS(libuuid/src)

AC_SUBST(XALT_INTERFACE_VERSION)
XALT_INTERFACE_VERSION=5
AH_TOP(
[
/* Remember that AC_DEFINE() end up in xalt_header.h.in
 * AC_SUBST() end up in xalt_config.h.in
 */
])

AC_SUBST(TRANSMISSION)
AC_ARG_WITH(transmission,
    AC_HELP_STRING([--with-transmission=ans],[transmission style (file,syslog,file_separate_dirs,curl) [[file]]]),
    TRANSMISSION="$withval"
    AC_MSG_RESULT([TRANSMISSION=$with_transmission])
    AC_DEFINE_UNQUOTED(TRANSMISSION, "$with_transmission",[transmission style (file,syslog,file_separate_dirs,curl)])dnl
    ,
    withval="file"
    AC_MSG_RESULT([TRANSMISSION=$withval])
    TRANSMISSION="$withval"
    AC_DEFINE_UNQUOTED(TRANSMISSION, "$withval",[transmission style (file,syslog,file_separate_dirs,curl)]))dnl

AC_SUBST(XALT_LOGGING_URL)
AC_ARG_WITH(xaltLoggingUrl,
    AC_HELP_STRING([--with-xaltLoggingUrl=ans],[Logging URL for transmission [[]]]),
    XALT_LOGGING_URL="$withval"
    AC_MSG_RESULT([XALT_LOGGING_URL=$with_xaltLoggingUrl])
    AC_DEFINE_UNQUOTED(XALT_LOGGING_URL, "$with_xaltLoggingUrl",[Logging URL for transmission])dnl
    ,
    withval="USE_ENV"
    AC_MSG_RESULT([XALT_LOGGING_URL=$withval])
    XALT_LOGGING_URL="$withval"
    AC_DEFINE_UNQUOTED(XALT_LOGGING_URL, "$withval",[Logging URL for transmission]))dnl

AC_SUBST(XALT_FUNCTION_TRACKING)
AC_ARG_WITH(functionTracking,
    AC_HELP_STRING([--with-functionTracking=ans],[Track functions from modules [[yes]]]),
    XALT_FUNCTION_TRACKING="$withval"
    AC_MSG_RESULT([XALT_FUNCTION_TRACKING=$with_functionTracking])
    AC_DEFINE_UNQUOTED(XALT_FUNCTION_TRACKING, "$with_functionTracking",[Track functions from modules])dnl
    ,
    withval="yes"
    AC_MSG_RESULT([XALT_FUNCTION_TRACKING=$withval])
    XALT_FUNCTION_TRACKING="$withval"
    AC_DEFINE_UNQUOTED(XALT_FUNCTION_TRACKING, "$withval",[Track functions from modules]))dnl

AC_SUBST(XALT_FILE_PREFIX)
AC_ARG_WITH(xaltFilePrefix,
    AC_HELP_STRING([--with-xaltFilePrefix=ans],[Prefix where the json files are written [[$HOME]]]),
    XALT_FILE_PREFIX="$withval"
    AC_MSG_RESULT([XALT_FILE_PREFIX=$with_xaltFilePrefix])
    AC_DEFINE_UNQUOTED(XALT_FILE_PREFIX, "$with_xaltFilePrefix",[Prefix where the json files are written])dnl
    ,
    withval="USE_HOME"
    AC_MSG_RESULT([XALT_FILE_PREFIX=$withval])
    XALT_FILE_PREFIX="$withval"
    AC_DEFINE_UNQUOTED(XALT_FILE_PREFIX, "$withval",[Prefix where the json files are written]))dnl

AC_SUBST(XALT_GPU_TRACKING)
AC_ARG_WITH(trackGPU,
    AC_HELP_STRING([--with-trackGPU=ans],[Track GPU executables {yes(nvml),no,dcgm,nvml}, [[no]]]),
    XALT_GPU_TRACKING="$withval"
    AC_MSG_RESULT([XALT_GPU_TRACKING=$with_trackGPU])
    AC_DEFINE_UNQUOTED(XALT_GPU_TRACKING, "$with_trackGPU",[Track GPU executables])dnl
    ,
    withval="no"
    AC_MSG_RESULT([XALT_GPU_TRACKING=$withval])
    XALT_GPU_TRACKING="$withval"
    AC_DEFINE_UNQUOTED(XALT_GPU_TRACKING, "$withval",[Track GPU executables]))dnl

AC_SUBST(XALT_MPI_TRACKING)
AC_ARG_WITH(trackMPI,
    AC_HELP_STRING([--with-trackMPI=ans],[Track MPI executables, [[yes]]]),
    XALT_MPI_TRACKING="$withval"
    AC_MSG_RESULT([XALT_MPI_TRACKING=$with_trackMPI])
    AC_DEFINE_UNQUOTED(XALT_MPI_TRACKING, "$with_trackMPI",[Track MPI executables])dnl
    ,
    withval="yes"
    AC_MSG_RESULT([XALT_MPI_TRACKING=$withval])
    XALT_MPI_TRACKING="$withval"
    AC_DEFINE_UNQUOTED(XALT_MPI_TRACKING, "$withval",[Track MPI executables]))dnl

AC_SUBST(XALT_SCALAR_TRACKING)
AC_ARG_WITH(trackScalarPrgms,
    AC_HELP_STRING([--with-trackScalarPrgms=ans],[Track non-mpi executables[[yes]]]),
    XALT_SCALAR_TRACKING="$withval"
    AC_MSG_RESULT([XALT_SCALAR_TRACKING=$with_trackScalarPrgms])
    AC_DEFINE_UNQUOTED(XALT_SCALAR_TRACKING, "$with_trackScalarPrgms",[Track non-mpi executables])dnl
    ,
    withval="yes"
    AC_MSG_RESULT([XALT_SCALAR_TRACKING=$withval])
    XALT_SCALAR_TRACKING="$withval"
    AC_DEFINE_UNQUOTED(XALT_SCALAR_TRACKING, "$withval",[Track non-mpi executables]))dnl


AC_SUBST(XALT_CMDLINE_RECORD)
AC_ARG_WITH(cmdlineRecord,
    AC_HELP_STRING([--with-cmdlineRecord=ans],[Record the program's execution command line[[yes]]]),
    XALT_CMDLINE_RECORD="$withval"
    AC_MSG_RESULT([XALT_CMDLINE_RECORD=$with_cmdlineRecord])
    AC_DEFINE_UNQUOTED(XALT_CMDLINE_RECORD, "$with_cmdlineRecord",[Record the program's execution command line])dnl
    ,
    withval="yes"
    AC_MSG_RESULT([XALT_CMDLINE_RECORD=$withval])
    XALT_CMDLINE_RECORD="$withval"
    AC_DEFINE_UNQUOTED(XALT_CMDLINE_RECORD, "$withval",[Record the program's execution command line]))dnl

AC_SUBST(COMPUTE_SHA1SUM)
AC_ARG_WITH(computeSHA1,
    AC_HELP_STRING([--with-computeSHA1=ans],[compute SHA1 sums on libraries, [[no]]]),
    COMPUTE_SHA1SUM="$withval"
    AC_MSG_RESULT([COMPUTE_SHA1SUM=$with_computeSHA1])
    AC_DEFINE_UNQUOTED(COMPUTE_SHA1SUM, "$with_computeSHA1",,[Compute SHAs sums on libraries])dnl
    ,
    withval="no"
    AC_MSG_RESULT([COMPUTE_SHA1SUM=$withval])
    COMPUTE_SHA1SUM="$withval"
    AC_DEFINE_UNQUOTED(COMPUTE_SHA1SUM, "$withval",[Compute SHAs sums on libraries]))dnl

AC_SUBST(ETC_DIR)
AC_ARG_WITH(etcDir,
    AC_HELP_STRING([--with-etcDir=ans],[Directory where xalt_db.conf and reverseMapD can be found [[.]]]),
    ETC_DIR="$withval"
    AC_MSG_RESULT([ETC_DIR=$with_etcDir])
    AC_DEFINE_UNQUOTED(ETC_DIR, "$with_etcDir",[Directory where xalt_db.conf and reverseMapD can be found])dnl
    ,
    withval="."
    AC_MSG_RESULT([ETC_DIR=$withval])
    ETC_DIR="$withval"
    AC_DEFINE_UNQUOTED(ETC_DIR, "$withval",[Directory where xalt_db.conf and reverseMapD can be found]))dnl

AC_SUBST(XALT_CONFIG_PY)
AC_ARG_WITH(config,
    AC_HELP_STRING([--with-config=ans],[A python file defining the accept, ignore, hostname pattern lists [[NO DEFAULT]]]),
    XALT_CONFIG_PY="$withval"
    AC_MSG_RESULT([XALT_CONFIG_PY=$with_config])
    AC_DEFINE_UNQUOTED(XALT_CONFIG_PY, "$with_config",[A python file defining the site configuration])dnl
    ,
    withval="no"
    AC_MSG_RESULT([XALT_CONFIG_PY=$withval])
    XALT_CONFIG_PY="$withval"
    AC_DEFINE_UNQUOTED(XALT_CONFIG_PY, "$withval",[A python file defining the site configuration]))dnl

AC_SUBST(MYSQLDB)
AC_ARG_WITH(MySQL,
    AC_HELP_STRING([--with-MySQL=ans],[Require the mysqlclient/MySQL-python module [[yes]]]),
    MYSQLDB="$withval"
    AC_MSG_RESULT([MYSQLDB=$with_MySQL])
    AC_DEFINE_UNQUOTED(MYSQLDB, "$with_MySQL",[Require the mysqlclient/MySQL-python module])dnl
    ,
    withval="yes"
    AC_MSG_RESULT([MYSQLDB=$withval])
    MYSQLDB="$withval"
    AC_DEFINE_UNQUOTED(MYSQLDB, "$withval",[Require the mysqlclient/MySQL-python module]))dnl

AC_SUBST(SYSTEM_PATH)
AC_ARG_WITH(systemPath,
    AC_HELP_STRING([--with-systemPath=[ans]],[]),
    SYSTEM_PATH="$withval"
    AC_MSG_RESULT([SYSTEM_PATH=$with_systemPath])
    AC_DEFINE_UNQUOTED(SYSTEM_PATH, "$with_systemPath",[The system path that XALT will use (typically /usr/bin:/bin)])dnl
    ,
    withval="/usr/bin:/bin"
    AC_MSG_RESULT([SYSTEM_PATH=$withval])
    SYSTEM_PATH="$withval"
    AC_DEFINE_UNQUOTED(SYSTEM_PATH, "$withval"[The system path that XALT will use (typically /usr/bin:/bin)]))dnl

AC_SUBST(SYSLOG_MSG_SZ)
AC_ARG_WITH(syslogMsgSz,
    AC_HELP_STRING([--with-syslogMsgSz=ans],[]),
    SYSLOG_MSG_SZ="$withval"
    AC_MSG_RESULT([SYSLOG_MSG_SZ=$with_syslogMsgSz])
    AC_DEFINE_UNQUOTED(SYSLOG_MSG_SZ, "$with_syslogMsgSz")dnl
    ,
    withval="512"
    AC_MSG_RESULT([SYSLOG_MSG_SZ=$withval])
    SYSLOG_MSG_SZ="$withval"
    AC_DEFINE_UNQUOTED(SYSLOG_MSG_SZ, "$withval"))dnl

AC_SUBST(CXX_LD_LIBRARY_PATH)
AC_ARG_WITH(cxxLDLibraryPath,
    AC_HELP_STRING([--with-cxxLDLibraryPath=ans],[LD_LIBRARY_PATH for c++ programs[[]]]),
    CXX_LD_LIBRARY_PATH="$withval"
    AC_MSG_RESULT([CXX_LD_LIBRARY_PATH=$with_cxxLDLibraryPath])
    AC_DEFINE_UNQUOTED(CXX_LD_LIBRARY_PATH, "$with_cxxLDLibraryPath")dnl
    ,
    withval=""
    AC_MSG_RESULT([CXX_LD_LIBRARY_PATH=$withval])
    CXX_LD_LIBRARY_PATH="$withval"
    AC_DEFINE_UNQUOTED(CXX_LD_LIBRARY_PATH, "$withval",[LD_LIBRARY_PATH for c++ programs]))dnl

AC_SUBST(SYSHOST_CONFIG)
AC_ARG_WITH(syshostConfig,
    AC_HELP_STRING([--with-syshostConfig=ans],[How to determine syshost[[no default]]]),
    SYSHOST_CONFIG="$withval"
    AC_MSG_RESULT([SYSHOST_CONFIG=$with_syshostConfig])
    AC_DEFINE_UNQUOTED(SYSHOST_CONFIG, "$with_syshostConfig",[How to determine syshost])dnl
    ,
    withval="no"
    AC_MSG_RESULT([SYSHOST_CONFIG=$withval])
    SYSHOST_CONFIG="$withval"
    AC_DEFINE_UNQUOTED(SYSHOST_CONFIG, "$withval",[How to determine syshost]))dnl

AC_SUBST(MY_HOSTNAME_PARSER)
AC_ARG_WITH(hostnameParser,
    AC_HELP_STRING([--with-hostnameParser=ans],[Replace built-in lex based hostname parser c_file:file.c or library:file_64.a or library:file_64.a:file_32.a [[no]]]),
    MY_HOSTNAME_PARSER="$withval"
    AC_MSG_RESULT([MY_HOSTNAME_PARSER=$with_hostnameParser])
    AC_DEFINE_UNQUOTED(MY_HOSTNAME_PARSER, "$with_hostnameParser",[Replace built-in lex based hostname parser])dnl
    ,
    withval="no"
    AC_MSG_RESULT([MY_HOSTNAME_PARSER=$withval])
    MY_HOSTNAME_PARSER="$withval"
    AC_DEFINE_UNQUOTED(MY_HOSTNAME_PARSER, "$withval",[Replace built-in lex based hostname parser]))dnl

AC_SUBST(STATIC_LIBS)
AC_ARG_WITH(staticLibs,
    AC_HELP_STRING([--with-staticLibs=ans],[Link with static libraries (currently only dcgm) [[no]]]),
    STATIC_LIBS="$withval"
    AC_MSG_RESULT([STATIC_LIBS=$with_staticLibs])
    AC_DEFINE_UNQUOTED(STATIC_LIBS, "$with_staticLibs",[Link with static libraries (currently only dcgm)])dnl
    ,
    withval="no"
    AC_MSG_RESULT([STATIC_LIBS=$withval])
    STATIC_LIBS="$withval"
    AC_DEFINE_UNQUOTED(STATIC_LIBS, "$withval",[Link with static libraries (currently only dcgm)]))dnl

AC_SUBST(PRELOAD_ONLY)
AC_ARG_WITH(preloadOnly,
    AC_HELP_STRING([--with-preloadOnly=ans],[Only use XALT in preload only mode[[yes]]]),
    PRELOAD_ONLY="$withval"
    AC_MSG_RESULT([PRELOAD_ONLY=$with_preloadOnly])
    AC_DEFINE_UNQUOTED(PRELOAD_ONLY, "$with_preloadOnly",[Only use XALT in preload only mode])dnl
    ,
    withval="yes"
    AC_MSG_RESULT([PRELOAD_ONLY=$withval])
    PRELOAD_ONLY="$withval"
    AC_DEFINE_UNQUOTED(PRELOAD_ONLY, "$withval",[Only use XALT in preload only mode]))dnl

AC_SUBST(BAD_INSTALL)
AC_ARG_WITH(IrefuseToInstallXALTCorrectly,
    AC_HELP_STRING([--with-IrefuseToInstallXALTCorrectly=ans],[Install XALT incorrectly [[no]]]),
    BAD_INSTALL="$withval"
    AC_MSG_RESULT([BAD_INSTALL=$with_IrefuseToInstallXALTCorrectly])
    AC_DEFINE_UNQUOTED(BAD_INSTALL, "$with_IrefuseToInstallXALTCorrectly",[A site that insist to install XALT incorrectly])dnl
    ,
    withval="no"
    AC_MSG_RESULT([BAD_INSTALL=$withval])
    BAD_INSTALL="$withval"
    AC_DEFINE_UNQUOTED(BAD_INSTALL, "$withval",[A site that insist to install XALT incorrectly]))dnl

AC_SUBST(BIT32)
AC_ARG_WITH(32bit,
    AC_HELP_STRING([--with-32bit],[Allow for 32 bits executables[[yes]]]),
    BIT32="$withval"
    AC_MSG_RESULT([BIT32=$with_32bit])
    AC_DEFINE_UNQUOTED(BIT32, "$with_32bit",[Build 32bit libraries as well])dnl
    ,
    withval="yes"
    AC_MSG_RESULT([BIT32=$withval])
    BIT32="$withval"
    AC_DEFINE_UNQUOTED(BIT32, "$withval",[Build 32bit libraries as well]))dnl

AC_SUBST(XALT_TMPDIR)
AC_ARG_WITH(tmpdir,
    AC_HELP_STRING([--with-tmpdir=ans],[The tmp directory to use with package records [[/dev/shm]]]),
    XALT_TMPDIR="$withval"
    AC_MSG_RESULT([XALT_TMPDIR=$with-tmpdir])
    AC_DEFINE_UNQUOTED(XALT_TMPDIR, "$with-tmpdir")dnl
    ,
    withval="/dev/shm"
    AC_MSG_RESULT([XALT_TMPDIR=$withval])
    XALT_TMPDIR="$withval"
    AC_DEFINE_UNQUOTED(XALT_TMPDIR, "$withval"))dnl

AC_SUBST(XALT_PRIME_NUMBER)
AC_ARG_WITH(primeNumber,
    AC_HELP_STRING([--with-primeNumber=ans],[The prime number of directories when using XALT_FILE_PREFIX, [[997]]]),
    XALT_PRIME_NUMBER="$withval"
    AC_MSG_RESULT([XALT_PRIME_NUMBER=$with-primeNumber])
    AC_DEFINE_UNQUOTED(XALT_PRIME_NUMBER, "$with-primeNumber")dnl
    ,
    withval="997"
    AC_MSG_RESULT([XALT_PRIME_NUMBER=$withval])
    XALT_PRIME_NUMBER="$withval"
    AC_DEFINE_UNQUOTED(XALT_PRIME_NUMBER, "$withval"))dnl

AC_SUBST(XALT_PRIME_FMT)
AC_SUBST(HAVE_32BIT)

if test "$BIT32" = yes ; then
  AX_TEST_COMPILE_FLAG([-m32],[HAVE_32BIT=yes],[HAVE_32BIT=no])
else
  HAVE_32BIT=no
fi

AC_LANG_PUSH(C++)
AX_TEST_COMPILE_FLAG([-std=c++11],[HAVE_CXX11=yes],[HAVE_CXX11=no])
AC_LANG_POP([C++])

AC_SUBST(PATH_TO_GIT)
AC_SUBST(PATH_TO_FLEX)
AC_SUBST(PATH_TO_LOGGER)
AC_SUBST(PATH_TO_PSTREE)

AC_SUBST(PATH_TO_UUIDGEN)

AC_SUBST(USE_CONTRIB_ARGPARSE)

AC_PATH_PROG(PATH_TO_GIT,git, [])
AC_PATH_PROG(PATH_TO_FLEX,flex, [])
AC_PATH_PROG(PATH_TO_LOGGER,logger, [])
AC_PATH_PROG(PATH_TO_MKTEMP, mktemp, [])
AC_PATH_PROGS(PATH_TO_PYTHON, [python3] [python2] [python], [])

if test "x$PATH_TO_PYTHON" = "x"; then
   echo
   echo "======================================================="
   echo "XALT 2 requires python3, python2 or python to run."
   echo "======================================================="
   echo
   rm -f makefile
   exit 1
fi

AC_SUBST(XALT_INSTALL_OS)
XALT_INSTALL_OS=$($ac_confdir/sh_src/xalt_print_os.in)
AC_DEFINE_UNQUOTED(XALT_INSTALL_OS,"$XALT_INSTALL_OS",[Name of the OS that installed XALT])


if test "x${PATH_TO_MKTEMP}" = "x" ; then
  AC_MSG_ERROR([Unable to build XALT without mktemp])
fi


transmission=`echo $TRANSMISSION | tr A-Z a-z`

found=no
for i in file file_separate_dirs syslog none; do
   if test $transmission = $i ; then
      found=yes
      break
   fi
done

if test found = no; then
   echo
   echo "======================================================="
   echo "XALT 2 does not support transmission style: $TRANSMISSION"
   echo "See the xalt.readthedocs.io for supported methods"
   echo "======================================================="
   echo
   rm -f makefile
   exit 1
fi

AC_SUBST(HAVE_PYMOD_MYSQLDB)
AX_PYTHON_MODULE([$PATH_TO_PYTHON],[MySQLdb])

AC_CHECK_HEADER(uuid/uuid.h,
                [AC_DEFINE([HAVE_UUID_UUID_H], 1,
                   [Define to 1 if you have <uuid/uuid.h>.])],
                [AC_MSG_ERROR([Unable to build XALT without uuid/uuid.h])])
AC_CHECK_HEADER(curl/curl.h,
                [AC_DEFINE([HAVE_CURL_CURL_H], 1,
                   [Define to 1 if you have <curl/curl.h>.])],
                [AC_MSG_ERROR([Unable to build XALT without curl/curl.h])])
AC_CHECK_HEADER(openssl/sha.h,
                [AC_DEFINE([HAVE_OPENSSL_SHA_H], 1,
                   [Define to 1 if you have <openssl/sha.h>.])],
                [AC_MSG_ERROR([Unable to build XALT without openssl/sha.h])])

AC_CHECK_HEADER(gelf.h, [],
                [AC_MSG_ERROR([Unable to build XALT without gelf.h. Please install the libelf development package])])


AC_SUBST(HAVE_WORKING_LIBUUID)
HAVE_WORKING_LIBUUID=no
if test $ac_cv_header_uuid_uuid_h = yes; then
  AC_SEARCH_LIBS([uuid_generate],[uuid], [AC_DEFINE(HAVE_LIBUUID,1, [libuuid exist]) HAVE_WORKING_LIBUUID=yes], [])
fi

if test $HAVE_WORKING_LIBUUID = no -a ! -f /proc/sys/kernel/random/uuid; then
   echo
   echo "======================================================="
   echo "Unable to install XALT without uuid and"
   echo "without /proc/sys/kernel/random/uuid"
   echo "See the manual for details"
   echo "======================================================="
   rm -f makefile
   exit 1
fi


if test -z "$PATH_TO_FLEX" ; then
   echo
   echo "======================================================="
   echo "Unable to install XALT without flex"
   echo "See the xalt.readthedocs.io for details"
   echo "======================================================="
   rm -f makefile
   exit 1
fi


AC_SUBST(HAVE_NVML)
HAVE_NVML=no
AC_SUBST(HAVE_DCGM)
HAVE_DCGM=no
if test $XALT_GPU_TRACKING = "dcgm" ; then
  AC_CHECK_HEADER(dcgm_agent.h,
                  [AC_DEFINE([HAVE_DCGM_AGENT_H], 1,
                     [Define to 1 if you have DCGM.])],
                  [AC_MSG_ERROR([Unable to include GPU tracking without DCGM])])
  if test "$STATIC_LIBS" = yes; then
    AC_SEARCH_LIBS([dcgmInit], [dcgm_stub], [AC_DEFINE(USE_DCGM, [1],[Using DCGM]) HAVE_DCGM=yes], [AC_MSG_ERROR([Unable to include GPU tracking without DCGM])], [-ldl])
  else
    AC_SEARCH_LIBS([dcgmInit], [dcgm], [AC_DEFINE(USE_DCGM, [1],[Using DCGM]) HAVE_DCGM=yes], [AC_MSG_ERROR([Unable to include GPU tracking without DCGM])])
  fi
elif test $XALT_GPU_TRACKING = yes || test $XALT_GPU_TRACKING = "nvml" ; then
  AC_CHECK_HEADER(nvml.h,
                  [AC_DEFINE([HAVE_NVML_H], 1,
                     [Define to 1 if you have NVML.])],
                  [AC_MSG_ERROR([Unable to include GPU tracking without NVML])])
  AC_CHECK_HEADER(dlfcn.h,
                  [AC_DEFINE([HAVE_DCFCN_H], 1,
                     [Define to 1 if you have dlfcn.h.])],
                  [AC_MSG_ERROR([Unable to include GPU tracking without dlfcn.h])])
  AC_SEARCH_LIBS([dlopen], [dl dld],
                 [AC_DEFINE([HAVE_DLOPEN], [1],[Using dlopen library])
                  AC_DEFINE([USE_NVML], [1],[Using NVML library])
                  HAVE_NVML=yes],
                 [AC_MSG_ERROR([Unable to find dlopen])])
fi

AC_SUBST(PKGV)
AC_SUBST(VERSION)
AC_SUBST(XALT_GIT_VERSION)

VERSION=$(cat $ac_confdir/.version | sed -e 's/-devel//g')
PKGV=$prefix/xalt/$VERSION

if test $BAD_INSTALL = no; then
   if echo $prefix | grep -i xalt/$VERSION > /dev/null ; then
      echo
      echo "===================================================="
      echo "Do not install XALT with $VERSION as part of the"
      echo "prefix.  It will lead to many many problems with future"
      echo "installs of XALT"
      echo
      echo "Executables built with the current version of XALT"
      echo "will not work with future installs of XALT!!!"
      echo
      echo "If you feel that you know better than the developer"
      echo "of XALT then you can configure XALT with the configure"
      echo "--with-IrefuseToInstallXALTCorrectly=yes and set the prefix"
      echo "to include the version"
      echo 
      echo "If you wanted to install XALT in /apps/xalt/$version"
      echo "set the prefix as:"
      echo
      echo "  ./configure --prefix=/apps"
      echo
      echo "===================================================="
      echo
      rm -f makefile
      exit 1
   fi
fi

echo "VERSION=$VERSION"
if test -n "$PATH_TO_GIT" -a -d $srcdir/.git ; then
  xaltV=`(cd $srcdir; $PATH_TO_GIT describe)`
else
  xaltV="@git@"
fi
XALT_GIT_VERSION=$xaltV

if test "$HAVE_CXX11" = no; then
   echo
   echo "======================================================="
   echo "Unable to install XALT without g++ supporting -std=c++11"
   echo "See the xalt.readthedocs.io for details"
   echo "======================================================="
   rm -f makefile
   exit 1
fi

if test "$XALT_CONFIG_PY" = no; then
   echo
   echo "======================================================="
   echo "Unable to install XALT without setting --with-config=..."
   echo "See the xalt.readthedocs.io for details"
   echo "======================================================="
   rm -f makefile
   exit 1
fi

if ! test -f $XALT_CONFIG_PY; then
   echo
   echo "======================================================="
   echo "Unable to find the file: $XALT_CONFIG_PY"
   echo "quitting!"
   echo "======================================================="
   rm -f makefile
   exit 1
fi

if test "$MYSQLDB" = yes; then
   if test "$HAVE_PYMOD_MYSQLDB" = no; then
      echo
      echo "======================================================="
      echo "Unable to install XALT without the python module: MySQLdb"
      echo "To install for python3 do: pip3 install mysqlclient"
      echo "To install for python2 do: pip  install MySQL-python"
      echo "======================================================="
      rm -f makefile
      exit 1
   fi
fi

if test "$SYSHOST_CONFIG" = no; then
   echo
   echo "======================================================="
   echo "Unable to install XALT without setting --with-syshostConfig=..."
   echo "Your choices are hardcode, nth_name, read_file, mapping,"
   echo "strip_nodename_numbers and env_var."
   echo "See the xalt.readthedocs.io for details."
   echo "======================================================="
   rm -f makefile
   exit 1
fi


printf "Use contrib argparse"
USE_CONTRIB_ARGPARSE=no
versionStr=$($PATH_TO_PYTHON --version 2>&1 | head -1)
major_version=`expr "$versionStr" : 'Python \+\([[0-9]]\+\)\.'`
minor_version=`expr "$versionStr" : 'Python \+[[0-9]]\+\.\([[0-9]]\+\)'`
version=`expr $major_version \* 100000 + $minor_version`
contrib_version=200007
if test $version -lt $contrib_version ; then
   USE_CONTRIB_ARGPARSE=yes
fi
echo "... $USE_CONTRIB_ARGPARSE"

if ! test -d src/__build__; then
   mkdir -p src/__build__
fi

if test "$USE_CONTRIB_ARGPARSE" = yes; then
   if test -z "$PYTHONPATH"; then
      export PYTHONPATH=$ac_confdir/contrib/argparse
   else
      export PYTHONPATH=$ac_confdir/contrib/argparse:$PYTHONPATH
   fi
fi

AC_SEARCH_LIBS([SHA1], [crypto], [], [AC_MSG_ERROR([Unable to build XALT without libcrypto])])
AC_SEARCH_LIBS([curl_easy_setopt], [curl], [], [AC_MSG_ERROR([Unable to build XALT without libcurl])])

MY_TMPDIR=`mktemp -d`

LOCATE_SO=$MY_TMPDIR/locate_shared_library

gcc -o $LOCATE_SO $ac_confdir/proj_mgmt/locate_shared_library.c -ldl

AC_SUBST(CRYPTO_STR)
CRYPTO_STR=`$LOCATE_SO libcrypto.so`

AC_SUBST(CURL_STR)
for i in ' ' .9 .8 .7 .6 .5 .4 .3 .2 .1; do
  CURL_STR=`$LOCATE_SO libcurl.so$i`
  if test "$?" -eq 0; then
    break;
  fi
done

AC_SUBST(UUID_STR)
for i in ' ' .9 .8 .7 .6 .5 .4 .3 .2 .1; do
  UUID_STR=`$LOCATE_SO libuuid.so$i`
  if test "$?" -eq 0; then
    break;
  fi
done


$PATH_TO_PYTHON $ac_confdir/proj_mgmt/py_build_tools/xalt_prime_check.py $XALT_PRIME_NUMBER
if test "$?" != 0; then
   echo
   echo "======================================================="
   echo "Unable to install XALT when --with-primeNumber=<ans>"
   echo "is not a prime number.  It also has to be bigger than 3."
   echo "See the xalt.readthedocs.io for details."
   echo "======================================================="
   rm -f makefile
   exit 1
fi
   
XALT_PRIME_FMT=$($PATH_TO_PYTHON $ac_confdir/proj_mgmt/py_build_tools/xalt_prime_fmt.py $XALT_PRIME_NUMBER)
if test "$?" != 0; then
   rm -f makefile
   exit 1
fi

$PATH_TO_PYTHON $ac_confdir/proj_mgmt/py_build_tools/build_xalt_interval_table.py --confFn $XALT_CONFIG_PY --input $ac_confdir/src/tmpl/xalt_interval.template --output src/__build__/xalt_interval.h
if test "$?" != 0; then
   rm -f makefile
   exit 1
fi

$PATH_TO_PYTHON $ac_confdir/proj_mgmt/py_build_tools/build_xalt_regex.py --confFn $XALT_CONFIG_PY --input $ac_confdir/src/tmpl/xalt_regex.template --output src/__build__/xalt_regex.h
if test "$?" != 0; then
   rm -f makefile
   exit 1
fi	

$PATH_TO_PYTHON $ac_confdir/proj_mgmt/py_build_tools/build_syshost_routine.py --input $SYSHOST_CONFIG --output src/__build__/xalt_syshost.c
if test "$?" != 0; then
   rm -f makefile
   exit 1
fi	

$PATH_TO_PYTHON $ac_confdir/proj_mgmt/py_build_tools/build_parser_routine.py --confFn $XALT_CONFIG_PY --pattern env_patterns --input $ac_confdir/src/tmpl/xalt_env_parser.template --output src/__build__/xalt_env_parser.lex
if test "$?" != 0; then
   rm -f makefile
   exit 1
fi	

$PATH_TO_PYTHON $ac_confdir/proj_mgmt/py_build_tools/build_parser_routine.py --confFn $XALT_CONFIG_PY --pattern path_patterns --input $ac_confdir/src/tmpl/xalt_path_parser.template --output src/__build__/xalt_path_parser.lex
if test "$?" != 0; then
   rm -f makefile
   exit 1
fi	

$PATH_TO_PYTHON $ac_confdir/proj_mgmt/py_build_tools/build_parser_routine.py --confFn $XALT_CONFIG_PY --pattern hostname_patterns --input $ac_confdir/src/tmpl/xalt_hostname_parser.template --output src/__build__/xalt_hostname_parser.lex
if test "$?" != 0; then
   rm -f makefile
   exit 1
fi	


#########################################################################
## check to see if the following programs can be found from SYSTEM_PATH:
#
ORIG_SEP=$IFS
IFS=':'
NOT_FOUND=""
for cmd in as basename bc cat date dirname file grep head ldd logger mkdir objdump readlink rm sha1sum sed; do
   found=""
   for dir in $SYSTEM_PATH; do
     if test -f $dir/$cmd && test -x $dir/$cmd; then
       found=1
       break
     fi
   done
   if test -z "$found" ; then
     NOT_FOUND="$cmd $NOT_FOUND"
   fi
done
   
IFS=$ORIG_SEP

if test -n "$NOT_FOUND"; then
  AC_MSG_ERROR([Unable to build XALT without SYSTEM_PATH=$SYSTEM_PATH including $NOT_FOUND])
fi  

  

AC_OUTPUT(makefile:Makefile.in src/__build__/xalt_config.h:src/xalt_config.h.in src/makefile:src/Makefile.in)

AX_SUMMARIZE_CONFIG
