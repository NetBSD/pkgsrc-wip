# $Id: win32.pkg.mk,v 1.16 2003/12/02 05:52:20 mpasternak Exp $
# (C) 2003 Michal Pasternak <dotz@irc.pl>
#
#
#	Naming convention for mingw packages:
# 
# mingw- 	means a native cross-build tool, like mingw-g++ 
#
# mingw32- 	means a tool compiled by mingw, which will work on win32
#
# when I'll be able to compile mingw-c with itself on cross platform, such
# package will be named mingw32-mingw-c
#

.include "../../mk/bsd.prefs.mk"

MINGWTARGET=		i586-pc-mingw32
MINGW_PKG_PREFIX=	mingw32-
GNU_CONFIGURE_PREFIX=	${CROSSBASE}/${MINGWTARGET}
# note, that we don't override this:
## MACHINE_GNU_PLATFORM=${MINGWTARGET}
# here, because of trouble "C compiler cannot execute test executable"
CONFIGURE_ARGS+=	--build=${MINGWTARGET}
CONFIGURE_ARGS+=	--program-transform-name="s|$$|.exe"

USE_CROSSBASE=	yes
PLIST_SUBST+=	MINGWTARGET=${MINGWTARGET}

PATH:=		${CROSSBASE}/${MINGWTARGET}/bin/:${PATH}
CC=		${CROSSBASE}/${MINGWTARGET}/bin/gcc
CXX=		${CROSSBASE}/${MINGWTARGET}/bin/g++
CPP=		${CROSSBASE}/${MINGWTARGET}/bin/cpp
LD=		${CROSSBASE}/${MINGWTARGET}/bin/ld
AR=		${CROSSBASE}/${MINGWTARGET}/bin/ar
AS=		${CROSSBASE}/${MINGWTARGET}/bin/as
NM=		${CROSSBASE}/${MINGWTARGET}/bin/nm
LDFLAGS=	-L${CROSSBASE}/${MINGWTARGET}/lib
CFLAGS=		-I${CROSSBASE}/include
CPPFLAGS=	-I${CROSSBASE}/include
CXXFLAGS=	-I${CROSSBASE}/include

.ifdef MINGW_STATIC
LIBTOOL=		${CROSSBASE}/${MINGWTARGET}/bin/libtool-static
CONFIGURE_ARGS+=	--enable-static --disable-shared
SHLIBTOOL:=		${LIBTOOL}
.else
CONFIGURE_ARGS+=	--enable-shared --disable-static
LIBTOOL=		${CROSSBASE}/${MINGWTARGET}/bin/libtool
SHLIBTOOL:=		${LIBTOOL}
.endif

.ifdef USE_PEACE
BUILD_DEPENDS+=		peace>=20030919:../../emulators/peace
.endif

.ifdef USE_WINE
BUILD_DEPENDS+=		wine>=20031016:../../emulators/wine
.endif

BUILD_DEPENDS+=	mingw-c>=3.1.1:../../wip/mingw-c
BUILD_DEPENDS+=	mingw-g++>=3.1.1:../../wip/mingw-g++
BUILD_DEPENDS+=	mingw-libtool>=20010614:../../wip/mingw-libtool
BUILD_DEPENDS+=	mingw-binutils>=2.14.90:../../wip/mingw-binutils
BUILD_DEPENDS+=	mingw-runtime-bin>=3.2:../../wip/mingw-runtime-bin
BUILD_DEPENDS+=	mingw-w32api-bin>=2.2:../../wip/mingw-w32api-bin

.ifndef MINGW_BULK_BUILD
NO_BIN_ON_CDROM=	"This is win32 package"
NO_SRC_ON_CDROM=	"This is win32 package source"
.endif

.include "../../mk/bsd.pkg.mk"
