# $NetBSD: Makefile,v 1.1 2014/10/06 12:33:56 makoto Exp $
#
PKGNAME=		rtl-sdr-0.5
CATEGORIES=		ham

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sdr.osmocom.org/trac/wiki/rtl-sdr
COMMENT=		Turns your Realtek RTL2832 based DVB dongle into a SDR receiver
LICENSE=		gnu-gpl-v2

GIT_REPOSITORIES=	master
GIT_MODULE.master=	rtl-sdr
GIT_REPO.master=	git://git.osmocom.org/rtl-sdr.git
#GIT_TAG.master=	v0.5.3  # in case to say git tag

USE_LANGUAGES+=		c c++
USE_TOOLS+=		gmake
USE_CMAKE=		yes
AUTO_MKDIRS=		yes

WRKSRC=			${WRKDIR}/${PKGBASE}

SUBST_CLASSES+=		destdir
SUBST_MESSAGE.destdir=	Replace install destination to ${DESTDIR}
SUBST_FILES.destdir=	build/cmake_install.cmake
SUBST_STAGE.destdir=	pre-install
SUBST_SED.destdir=	-e 's|\$${CMAKE_INSTALL_PREFIX}|${DESTDIR}\$${CMAKE_INSTALL_PREFIX}|'

CMAKE_CONFIGURE_ARGS+=		-Wno-dev
CMAKE_CONFIGURE_ARGS+=		-DCMAKE_BUILD_WITH_INSTALL_RPATH=TRUE
CMAKE_CONFIGURE_ARGS+=		-DCMAKE_INSTALL_PREFIX=${PREFIX}
CMAKE_CONFIGURE_ARGS+=		-DCMAKE_INSTALL_RPATH=${PREFIX}/lib
CMAKE_CONFIGURE_ARGS+=		-DCMAKE_INSTALL_RPATH_USE_LINK_PATH=FALSE

CMAKE_ARG_PATH=		../
CONFIGURE_DIRS=		build

pre-configure:
	${MKDIR} ${WRKSRC}/build

do-build:
	(cd ${WRKSRC}/build; ${GMAKE})

do-install:
	(cd ${WRKSRC}/build; ${GMAKE} install)

.include "../../wip/mk/git-package.mk"
.include "../../devel/libusb1/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
