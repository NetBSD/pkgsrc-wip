AC_INIT([libpgf],[6.14.12])
AC_CONFIG_SRCDIR([src/PGFimage.cpp])

dnl pkgsrc comment
dnl This files is converted to \n line endings.
dnl It also adds --enable-doc option so that users can install libpgf 
dnl without having to install doxygen.
dnl In case of version update of libpgf make sure that this file is 
dnl updated accordingly. 
dnl end pkgsrc comment

dnl The library interface version
dnl see documentation for versioning in the libtool manual
dnl NOTE: these should only be updated before public releases

dnl The current version of the interface. If interfaces has been 
dnl added removed changed bump this
INTERFACE_CURRENT=6

dnl If the source has been changed bump this
INTERFACE_REVISION=11

dnl If any interfaces has been added since last release, bump this
dnl If any interfaces has been removed, set this to 0
dnl The age is always less than CURRENT
INTERFACE_AGE=0

INTERFACE_VERSION=$INTERFACE_CURRENT:$INTERFACE_REVISION:$INTERFACE_AGE

AC_SUBST(INTERFACE_VERSION)

PACKAGE_RELEASE=2

AC_SUBST(PACKAGE_RELEASE)

AM_INIT_AUTOMAKE
AC_PROG_LIBTOOL
AC_CONFIG_HEADERS( config.h )
AC_PROG_CXX

dnl Check for doxygen support
AC_ARG_ENABLE([doc],[AS_HELP_STRING([--enable-doc],[build docs])])
if test $enable_doc; then
AC_PATH_PROG([DOXYGEN], [doxygen])
AC_PATH_PROG([DOT], [dot])
fi
AM_CONDITIONAL(HAS_DOXYGEN, test $DOXYGEN && $DOT)

# Generate output
AC_OUTPUT(Makefile
    src/Makefile
    include/Makefile
    doc/Makefile
    doc/Doxyfile
    libpgf.spec
    libpgf.pc
)
