# $NetBSD: Makefile,v 1.7 2014/10/06 13:31:51 makoto Exp $

DISTNAME=		gr-osmosdr-0.1.4
CATEGORIES=		ham

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sdr.osmocom.org/trac/wiki/GrOsmoSDR
COMMENT=		SDR Hardware support for OsmoSDR and so many more
LICENSE=		gnu-gpl-v2

GIT_REPOSITORIES=	master
GIT_REPO.master=	git://git.osmocom.org/gr-osmosdr
GIT_MODULE.master=	gr-osmosdr

USE_LANGUAGES=		c c++
USE_TOOLS=		cmake
USE_CMAKE=		yes

WRKSRC=			${WRKDIR}/gr-osmosdr

# Suppress warning for developer
CMAKE_ARGS+=	-Wno-dev
# --   * Ettus USRP Devices
CMAKE_ARGS+=	-DGNURADIO_UHD_INCLUDE_DIRS=${PREFIX}/include/uhd
CMAKE_ARGS+=	-DGNURADIO_BLOCKS_INCLUDE_DIRS=${PREFIX}/include

PLIST_SUBST+=	PYSITELIB=${PYSITELIB}

REPLACE_PYTHON+=	apps/osmocom_siggen_base.py

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
.include	"../../wip/rtl-sdr-git/buildlink3.mk"
.include	"../../wip/libmirisdr-git/buildlink3.mk"
.include	"../../wip/osmo-sdr-git/buildlink3.mk"
.include	"../../wip/gr-fcdproplus-git/buildlink3.mk"

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
