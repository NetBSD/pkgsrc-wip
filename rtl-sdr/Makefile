# $NetBSD: Makefile,v 1.4 2014/09/08 14:17:23 makoto Exp $
#
DISTNAME=		v0.5.3
PKGNAME=		rtl-sdr-${DISTNAME:C/v//}
CATEGORIES=		ham
MAINTAINER=		pkgsrc-users@NetBSD.org
MASTER_SITES=		-https://github.com/steve-m/librtlsdr/archive/${DISTNAME}${EXTRACT_SUFX}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sdr.osmocom.org/trac/wiki/rtl-sdr
COMMENT=		Turns your Realtek RTL2832 based DVB dongle into a SDR receiver
LICENSE=		gnu-gpl-v2

BUILD_DEPENDS+=		ninja-build-[0-9]*:../../devel/ninja-build

DIST_SUBDIR=		rtl-sdr
USE_LANGUAGES+=		c c++
USE_TOOLS+=		cmake gmake
USE_CMAKE=		yes
WRKSRC=			${WRKDIR}/librtlsdr
AUTO_MKDIRS=		yes

SUBST_CLASSES+=		destdir
SUBST_MESSAGE.destdir=	Replace install destination to ${DESTDIR}
SUBST_FILES.destdir=	build/cmake_install.cmake
SUBST_STAGE.destdir=	pre-install
SUBST_SED.destdir=	-e 's|\$${CMAKE_INSTALL_PREFIX}|${DESTDIR}\$${CMAKE_INSTALL_PREFIX}|'

do-configure:
	(cd ${WRKSRC}; \
	${MKDIR} build; \
	cd build; \
	cmake \
	-DCMAKE_BUILD_WITH_INSTALL_RPATH=TRUE \
	-DCMAKE_INSTALL_PREFIX=${PREFIX} \
	-DCMAKE_INSTALL_RPATH=${PREFIX}/lib \
	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH=FALSE \
	../; \
	)

do-build:
	(cd ${WRKSRC}/build; ${GMAKE})

do-install:
	(cd ${WRKSRC}/build; ${GMAKE} install)

.include "../../lang/python/pyversion.mk"
.include "../../lang/${PYPACKAGE}/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
