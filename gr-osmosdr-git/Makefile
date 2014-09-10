# $NetBSD: Makefile,v 1.2 2014/09/10 01:50:31 makoto Exp $

DISTNAME=		gr-osmosdr-0.1.4
CATEGORIES=		ham

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sdr.osmocom.org/trac/wiki/GrOsmoSDR
COMMENT=		SDR Hardware support for OsmoSDR and so many more
LICENSE=		gnu-gpl-v2

.if 0
PKG_FAIL_REASON= ' ***  Package not completed yet. Sorry and thanks.'
.else
# Just for debugging purpose
MAKE_JOBS_SAFE=		no
.endif

GIT_REPOSITORIES=       master
GIT_REPO.master=        git://git.osmocom.org/gr-osmosdr
GIT_MODULE.master=	gr-osmosdr

USE_LANGUAGES=		c c++
USE_TOOLS=		cmake
USE_CMAKE=		yes
# /usr/include/g++/cmath:111:11: error: '::acos' has not been declared
# CXXFLAGS+=	-I/usr/include/g++/tr1

WRKSRC=			${WRKDIR}/gr-osmosdr

# Supress warning for developer
CMAKE_ARGS+=	-Wno-dev
# --   * Ettus USRP Devices
CMAKE_ARGS+=	-DGNURADIO_UHD_INCLUDE_DIRS=${PREFIX}/include/uhd

.include "../../wip/mk/git-package.mk"
# you need place after above line for now.
_GIT_FLAGS=		# set empty, --depth 1 seems harmfull
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/orc/buildlink3.mk"

.include "../../ham/uhd/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../wip/gnuradio-core/buildlink3.mk"
.include "../../wip/rtl-sdr/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
