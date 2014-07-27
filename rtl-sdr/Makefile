# $NetBSD: Makefile,v 1.1 2014/07/27 07:40:36 makoto Exp $
#
DISTNAME=		rtl-sdr-0.1
CATEGORIES=		ham

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sdr.osmocom.org/trac/wiki/rtl-sdr
COMMENT=		Turns your Realtek RTL2832 based DVB dongle into a SDR receiver
LICENSE=		gnu-gpl-v2

BUILD_DEPENDS+=		ninja-devel-[0-9]*:../../wip/ninja-devel

GIT_REPOSITORIES=	master
GIT_MODULE.master=	rtl-sdr
GIT_REPO.master=	git://git.osmocom.org/rtl-sdr.git
GIT_FLAGS?=		--depth 1

USE_LANGUAGES+=		c c++
USE_TOOLS+=		cmake gmake ldconfig
AUTO_MKDIRS=		yes

WRKSRC=			${WRKDIR}/${PKGBASE}

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

post-install:
	(cd ${WRKSRC}/build; ldconfig)

.include "../../wip/mk/git-package.mk"
.include "../../lang/python/pyversion.mk"
.include "../../lang/${PYPACKAGE}/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
