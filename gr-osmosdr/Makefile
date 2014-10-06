# $NetBSD: Makefile,v 1.4 2014/10/06 14:39:35 makoto Exp $

DISTNAME=		gr-osmosdr-0.1.3
CATEGORIES=		ham
MASTER_SITES+=		http://git.osmocom.org/gr-osmosdr/snapshot/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://git.osmocom.org/gr-osmosdr
COMMENT=		SDR Hardware support for OsmoSDR and so many more
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS=		cmake
USE_CMAKE=		yes

# Suppress warning for developer
CMAKE_ARGS+=	-Wno-dev
# --   * Ettus USRP Devices
CMAKE_ARGS+=	-DGNURADIO_UHD_INCLUDE_DIRS=${PREFIX}/include/uhd
CMAKE_ARGS+=	-DGNURADIO_BLOCKS_INCLUDE_DIRS=${PREFIX}/include

PLIST_SUBST+=	PYSITELIB=${PYSITELIB}

REPLACE_PYTHON+=	apps/osmocom_siggen_base.py

.include	"../../devel/boost-headers/buildlink3.mk"
.include	"../../devel/boost-libs/buildlink3.mk"
.include	"../../devel/libusb1/buildlink3.mk"
.include	"../../devel/orc/buildlink3.mk"

.include	"../../ham/uhd/buildlink3.mk"
.include	"../../lang/python/application.mk"
.include	"../../lang/python/extension.mk"

.include	"../../wip/rtl-sdr/buildlink3.mk"
.include	"../../wip/libmirisdr/buildlink3.mk"
.include	"../../wip/osmo-sdr/buildlink3.mk"
.include	"../../wip/gr-fcdproplus/buildlink3.mk"
.include	"../../wip/hackrf/buildlink3.mk"

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
