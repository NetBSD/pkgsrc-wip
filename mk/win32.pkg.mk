# $Id: win32.pkg.mk,v 1.2 2003/12/01 02:19:00 mpasternak Exp $
# (C) 2003 Michal Pasternak <dotz@irc.pl>
#
#
#	Naming convention for mingw packages:
# 
# mingw- 	means a native cross-build tool
# mingw32- 	means a tool compiled by mingw, which will work on win32
#

.include "../../mk/bsd.prefs.mk"

MINGWTARGET=		i586-pc-mingw32
MINGW_PKG_PREFIX=	mingw32-
GNU_CONFIGURE_PREFIX=	${CROSSBASE}/i586-pc-mingw32
CONFIGURE_ARGS+=	--build=i586-pc-mingw32

# note, that we don't override this:
## MACHINE_GNU_PLATFORM=i586-pc-mingw32
# here, because of trouble "C compiler cannot execute test executable"

PATH:=	${CROSSBASE}/i586-pc-mingw32/bin/:${PATH}
CC=	${CROSSBASE}/i586-pc-mingw32/bin/gcc
CPP=	${CROSSBASE}/i586-pc-mingw32/bin/cpp
LD=	${CROSSBASE}/i586-pc-mingw32/bin/ld
AR=	${CROSSBASE}/i586-pc-mingw32/bin/ar
AS=	${CROSSBASE}/i586-pc-mingw32/bin/as
NM=	${CROSSBASE}/i586-pc-mingw32/bin/nm
LIBTOOL=${CROSSBASE}/i586-pc-mingw32/bin/libtool

.include "../../mk/bsd.pkg.mk"
