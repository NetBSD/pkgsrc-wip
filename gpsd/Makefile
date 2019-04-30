# $NetBSD: Makefile,v 1.41 2019/04/26 14:12:39 maya Exp $

DISTNAME=	gpsd-3.18
CATEGORIES=	geography
MASTER_SITES=	http://download-mirror.savannah.gnu.org/releases/gpsd/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://savannah.nongnu.org/projects/gpsd
COMMENT=	GPS information daemon

LICENSE=	modified-bsd

PY_PATCHPLIST=	yes
#PYTHON_VERSIONS_INCOMPATIBLE=	36 37 # not yet ported as of 2.96

USE_TOOLS+=	pkg-config gmake
USE_LIBTOOL=	yes
USE_LANGUAGES=	c99 c++

NO_CONFIGURE=	yes


# gpsd looks for ncurses but not curses. (Not yet filed upstream.)
FAKE_NCURSES=	yes

# gpsd uses syncok
USE_CURSES=	syncok

# \todo Add a USE_TOOLS entry for scons.  SCONSBIN is open-coded
# because using the bl3 depends on a python that is incompatible with
# gpsd's python version, and we are using a tool, not buildlinking.
#BUILD_DEPENDS+=		py*-scons-[0-9]*:../../devel/scons
#SCONSBIN=		${PREFIX}/bin/scons

# \todo In theory this is not necessary.
BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

CFLAGS.SunOS=	-DLOG_PERROR=0

# \todo Resolve options
# nmea2000 = False (default True): NMEA2000/CAN support
# rtcm104v2 = False (default True): rtcm104v2 support
# pps = False (default True): PPS time syncing support
# dbus_export = False (default True): enable DBUS export support
# libgpsmm = False (default True): build C++ bindings
# qt?

# \todo: Separate configure phase

WRAPPER_DEBUG=	yes

do-build:
	cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${SCONSBIN} \
	-j${MAKE_JOBS:U1}
#	CC=${CC:Q} CXX=${CXX:Q} \

do-install:
	cd ${WRKSRC} && ./install.sh ${DESTDIR}${PREFIX}

#INSTALLATION_DIRS=	sbin

#TEST_TARGET=	check

PYTHON_FOR_BUILD_ONLY?=	yes
.include "../../devel/scons/buildlink3.mk"

.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
