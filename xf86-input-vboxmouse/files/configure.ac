# minimal autoconf goop to build vboxmouse outside the VirtualBox framework

AC_PREREQ([2.60])
AC_INIT([xf86-input-vboxmouse], [5.0.4])
AC_CONFIG_SRCDIR([Makefile.am])
AC_CONFIG_AUX_DIR(.)
AC_SYS_LARGEFILE

AM_INIT_AUTOMAKE([foreign])
AM_MAINTAINER_MODE

m4_ifndef([XORG_MACROS_VERSION],
          [m4_fatal([must install xorg-macros 1.8 or later before running autoconf/autogen])])
XORG_MACROS_VERSION(1.8)
XORG_DEFAULT_OPTIONS

AC_DISABLE_STATIC
AC_PROG_LIBTOOL
AM_PROG_CC_C_O

# Define a configure option for an alternate module directory
AC_ARG_WITH(xorg-module-dir,
            AS_HELP_STRING([--with-xorg-module-dir=DIR],
                           [Default xorg module directory [[default=$libdir/xorg/modules]]]),
            [moduledir="$withval"],
            [moduledir="$libdir/xorg/modules"])

PKG_CHECK_MODULES(XORG, [xorg-server >= 1.17.0])
PKG_CHECK_EXISTS([xorg-server >= 1.17.0 ],
                 [AC_DEFINE([HAVE_XORG_SERVER_1_17_0], 1,
                 [Has version 1.17.0 or greater of the Xserver])])

AC_SUBST([moduledir])

AC_CONFIG_FILES([Makefile])

RT_OS="$(uname -s | tr a-z A-Z)"
if [ "${RT_OS}" = "SUNOS" ]; then
   RT_OS=SOLARIS
fi

CPPFLAGS="${CPPFLAGS} -I../../../../../include -DIN_RING3 -DRT_OS_${RT_OS}"
cat > product-generated.h << EOF
#include "xorg-server.h"

#define VBOX_VERSION_MAJOR 5
#define VBOX_VERSION_MINOR 0
#define VBOX_VERSION_BUILD 4
#define VBOX_VERSION_STRING "5.0.4"
#define VBOX_VENDOR "The NetBSD Foundation, inc."
#define VBOX_SVN_REV 0
EOF

AC_OUTPUT
