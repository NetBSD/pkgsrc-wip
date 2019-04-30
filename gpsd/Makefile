# $NetBSD: Makefile,v 1.41 2019/04/26 14:12:39 maya Exp $

DISTNAME=	gpsd-3.18
CATEGORIES=	geography
MASTER_SITES=	http://download-mirror.savannah.gnu.org/releases/gpsd/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://savannah.nongnu.org/projects/gpsd
COMMENT=	GPS information daemon

LICENSE=	modified-bsd

PY_PATCHPLIST=	yes

USE_TOOLS+=	pkg-config gmake
USE_LIBTOOL=	yes
USE_LANGUAGES=	c99 c++

# \todo Separate upstream's build into configure and build.
NO_CONFIGURE=	yes

# \todo Check if this is necessary.
# gpsd looks for ncurses but not curses. (Not yet filed upstream.)
FAKE_NCURSES=	yes
# gpsd uses syncok
USE_CURSES=	syncok

SUBST_CLASSES+=		pyenv
SUBST_MESSAGE.pyenv=	Fixing path in Python scripts
SUBST_STAGE.pyenv=	pre-build	# We don't configure :-(
SUBST_FILES.pyenv+=	gegps
SUBST_FILES.pyenv+=	gpscat
SUBST_FILES.pyenv+=	gpsfake
SUBST_FILES.pyenv+=	gpsprof
SUBST_FILES.pyenv+=	ubxtool
SUBST_FILES.pyenv+=	zerk
SUBST_SED.pyenv=	-e 's,/usr/bin/env python.*$$,${PYTHONBIN},'

# \todo Check if this is necessary.
BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

CFLAGS.SunOS=	-DLOG_PERROR=0

# Configure phase arguments:
SCONS_ARGS+=	leapfetch=no		# Do not use the net at build time.
SCONS_ARGS+=	target_python=${PYTHONBIN}

# \todo: Determine if CC/CXX are needed here.
#	CC=${CC:Q} CXX=${CXX:Q}
do-build:
	cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${SCONSBIN} \
	prefix=${PREFIX} mandir=${PREFIX}/${PKGMANDIR} \
	${SCONS_ARGS} \
	-j${MAKE_JOBS:U1}

do-install:
	cd ${WRKSRC} && \
	${SETENV} ${INSTALL_ENV} ${SCONSBIN} install

do-test:
	cd ${WRKSRC} && \
	${SETENV} ${INSTALL_ENV} ${SCONSBIN} check

# \todo Change to TOOLS or BUILD_DEPENDS after scons is improved.
.include "../../devel/scons/buildlink3.mk"

.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
