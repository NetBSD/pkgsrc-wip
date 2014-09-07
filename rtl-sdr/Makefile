# $NetBSD: Makefile,v 1.2 2014/09/07 08:17:19 makoto Exp $
#
DISTNAME=		v0.5.3
PKGNAME=		librtlsdr-${DISTNAME:C/v//}
CATEGORIES=		ham
MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sdr.osmocom.org/trac/wiki/rtl-sdr
COMMENT=		Turns your Realtek RTL2832 based DVB dongle into a SDR receiver
MASTER_SITE=		https://github.com/steve-m/librtlsdr/archive
LICENSE=		gnu-gpl-v2
DISTDIR_SUBDIR=		rtl-sdr

BUILD_DEPENDS+=		ninja-devel-[0-9]*:../../wip/ninja-devel

USE_LANGUAGES+=		c c++
USE_TOOLS+=		cmake gmake ldconfig
AUTO_MKDIRS=		yes

WRKSRC=			${WRKDIR}/${PKGNAME}

SUBST_CLASSES+=		destdir
SUBST_MESSAGE.destdir=	Replace install destination to ${DESTDIR}
SUBST_FILES.destdir=	build/cmake_install.cmake
SUBST_STAGE.destdir=	pre-install
SUBST_SED.destdir=	-e 's|\$${CMAKE_INSTALL_PREFIX}|${DESTDIR}\$${CMAKE_INSTALL_PREFIX}|'

# FETCH_USING at /etc/mk.conf doesn't good, (sorry), put work around for the target
do-fetch:
	if [   ! -f ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} ] ; then \
	  if [ ! -d ${DISTDIR}/${DIST_SUBDIR} ] ; then \
	   mkdir -f ${DISTDIR}/${DIST_SUBDIR}; fi; \
	  cd      ${DISTDIR}/${DIST_SUBDIR}; \
	  wget --no-check-certificate --quiet ${MASTER_SITE}/${DISTNAME}${EXTRACT_SUFX} ;fi

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

.include "../../lang/python/pyversion.mk"
.include "../../lang/${PYPACKAGE}/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
