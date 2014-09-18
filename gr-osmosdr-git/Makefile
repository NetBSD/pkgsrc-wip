# $NetBSD: Makefile,v 1.3 2014/09/18 03:00:28 makoto Exp $

DISTNAME=		gr-osmosdr-0.1.4
CATEGORIES=		ham

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sdr.osmocom.org/trac/wiki/GrOsmoSDR
COMMENT=		SDR Hardware support for OsmoSDR and so many more
LICENSE=		gnu-gpl-v2

.if 1
PKG_FAIL_REASON= ' *** Currently /usr/include/g++/cmath patch is necessary. See TODO. Why ?'
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

WRKSRC=			${WRKDIR}/gr-osmosdr

# Supress warning for developer
CMAKE_ARGS+=	-Wno-dev
# --   * Ettus USRP Devices
#MAKE_ARGS+=	-DGNURADIO_UHD_LIBRARIES=${PREFIX}/lib
CMAKE_ARGS+=	-DGNURADIO_UHD_INCLUDE_DIRS=${PREFIX}/include/uhd
#CMAKE_ARGS+=	-DGNURADIO_BLOCKS_LIBRARIES=${PREFIX}/lib
CMAKE_ARGS+=	-DGNURADIO_BLOCKS_INCLUDE_DIRS=${PREFIX}/include
#CMAKE_ARGS+=	-DCMAKE_INCLUDE_PATH=${PREFIX}/include
#  gnuradio/fcd/source_c.h: No such file or directory
#CMAKE_ARGS+=	-DGNURADIO_FCD_LIBRARIES=${PREFIX}/lib

#CMAKE_ARGS+=	-DGNURADIO_INCLUDE_DIRS=${PREFIX}/include
PLIST_SUBST+=	PYSITELIB=${PYSITELIB}

.include "../../wip/mk/git-package.mk"
# you need place after above line for now.
_GIT_FLAGS=		# set empty, --depth 1 seems harmfull

.include	"../../devel/boost-headers/buildlink3.mk"
.include	"../../devel/boost-libs/buildlink3.mk"
.include	"../../devel/libusb1/buildlink3.mk"
.include	"../../devel/orc/buildlink3.mk"

.include	"../../ham/uhd/buildlink3.mk"
.include	"../../lang/python/application.mk"
.include	"../../lang/python/extension.mk"
.include	"../../wip/rtl-sdr/buildlink3.mk"

.if 1
# gnuradio/io_signature.h: No such file or directory
.  include "../../wip/gnuradio-core/buildlink3.mk"
# gnuradio/fcd/source_c.h: No such file or directory
.  include "../../wip/gnuradio-fcd/buildlink3.mk"
# gnuradio/uhd/usrp_source.h: No such file or directory
.  include "../../wip/gnuradio-uhd/buildlink3.mk"
.else
.  include "../../wip/gnuradio-default/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
