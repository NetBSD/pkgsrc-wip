# $Id: win32.pkg.mk,v 1.3 2003/12/01 02:26:12 mpasternak Exp $
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
GNU_CONFIGURE_PREFIX=	${CROSSBASE}/i586-pc-mingw32
# note, that we don't override this:
## MACHINE_GNU_PLATFORM=i586-pc-mingw32
# here, because of trouble "C compiler cannot execute test executable"
CONFIGURE_ARGS+=	--build=i586-pc-mingw32

PATH:=		${CROSSBASE}/i586-pc-mingw32/bin/:${PATH}
CC=		${CROSSBASE}/i586-pc-mingw32/bin/gcc
CPP=		${CROSSBASE}/i586-pc-mingw32/bin/cpp
LD=		${CROSSBASE}/i586-pc-mingw32/bin/ld
AR=		${CROSSBASE}/i586-pc-mingw32/bin/ar
AS=		${CROSSBASE}/i586-pc-mingw32/bin/as
NM=		${CROSSBASE}/i586-pc-mingw32/bin/nm
LIBTOOL=	${CROSSBASE}/i586-pc-mingw32/bin/libtool

BUILD_DEPENDS+=	mingw-c>=3.1.1:../../wip/mingw-c
BUILD_DEPENDS+=	mingw-binutils>=2.14.90:../../wip/mingw-binutils
BUILD_DEPENDS+=	mingw-runtime-bin>=3.2:../../wip/mingw-runtime-bin
BUILD_DEPENDS+=	mingw-w32api-bin>=2.2:../../wip/mingw-w32api-bin

.include "../../mk/bsd.pkg.mk"
