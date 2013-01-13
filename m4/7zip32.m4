dnl
dnl Configure 7zip32
dnl This file is included by the toplevel configure.ac
dnl

dnl
dnl process with-7zip32
dnl

dnl Use 7zip32 unless explicitly specified otherwise
ac_cv_use_7zip32=yes
SEVENZIP_CFLAGS=
SEVENZIP_LDFLAGS=
SEVENZIP_LIBS=-l7zip32

AC_ARG_WITH(7zip32,
  AC_HELP_STRING([--with-7zip32=PATH],
                 [Use 7zip32 library installed under PATH.
The os.windows.7zip32 module uses 7zip32 if it is available.  If your system has 7zip32
library in non-trivial location, specify this option.
The include file is looked for in PATH/include,
and the library file is looked for in PATH/lib.
If you don't want to use 7zip32 for some reason, say --without-7zip32. ]),
  [
  case $with_7zip32 in
    no)  ac_cv_use_7zip32=no;;
    yes) ;;
    *)   SEVENZIP_CFLAGS="-I$with_7zip32/include";
         SEVENZIP_LDFLAGS="-L$with_7zip32/lib";;
  esac
 ])

dnl
dnl Check 7-zip32.h
dnl

if test "$ac_cv_use_7zip32" != no; then
  save_cflags="$CFLAGS"
  CFLAGS="$CFLAGS $SEVENZIP_CFLAGS"
  AC_CHECK_HEADERS([7-zip32.h],
     AC_DEFINE(HAVE_SEVENZIP_H,1,[Define if you have 7-zip32.h and want to use it]),
     [AC_MSG_WARN("Can't find 7-zip32.h so I turned off using 7zip32; you may want to use --with-7zip32=PATH.")
      ac_cv_use_7zip32=no], [#include <windows.h>])
  CFLAGS=$save_cflags
fi

dnl
dnl Check lib7zip32.
dnl

if test "$ac_cv_use_7zip32" = yes; then
  save_cflags="$CFLAGS"
  save_ldflags="$LDFLAGS"
  save_libs="$LIBS"
  CFLAGS="$CFLAGS $SEVENZIP_CFLAGS"
  LDFLAGS="$LDFLAGS $SEVENZIP_LDFLAGS"
  LIBS="$LIBS -l7zip32"
  AC_LINK_IFELSE(
    [AC_LANG_PROGRAM([#include <windows.h>
                      #include <7-zip32.h>],
                     [[SevenZipGetVersion();]])],
    [SEVENZIP_LIB="-l7zip32"],
    [AC_MSG_WARN("Can't find lib7zip32 so I turned off using 7zip32; you may want to use --with-7zip32=PATH")
      ac_cv_use_7zip32=no])
  CFLAGS="$save_cflags"
  LDFLAGS="$save_ldflags"
  LIBS="$save_libs"
fi

if test "$ac_cv_use_sevenzip32" = yes; then
  AC_DEFINE(USE_SEVENZIP)
  SEVENZIP_ARCHFILES=7zip32.$SHLIB_SO_SUFFIX
  AC_SUBST(SEVENZIP_ARCHFILES)
  sevenzip32_SCMFILES=7zip32.scm
  AC_SUBST(SEVENZIP_SCMFILES)
fi
AC_SUBST(SEVENZIP_CFLAGS)
AC_SUBST(SEVENZIP_LDFLAGS)
AC_SUBST(SEVENZIP_LIBS)

dnl Local variables:
dnl mode: autoconf
dnl end:
