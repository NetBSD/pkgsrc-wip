# $NetBSD: Makefile,v 1.24 2020/05/06 14:04:43 adam Exp $

DISTNAME=		gr-osmosdr-0.2.0
CATEGORIES=		ham
# main git repo doesn't allow snapshots to be downloaded
#MASTER_SITES=		https://git.osmocom.org/gr-osmosdr/snapshot/
MASTER_SITES=		${MASTER_SITE_GITHUB:=osmocom/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://git.osmocom.org/gr-osmosdr
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
# TODO: make it PKG_OPTION
CMAKE_ARGS+=	-DENABLE_DOXYGEN=OFF

PLIST_SUBST+=	PYSITELIB=${PYSITELIB}

PYTHON_VERSIONS_ACCEPTED=	37
REPLACE_PYTHON+=		apps/osmocom_siggen_base.py

.include	"../../devel/boost-headers/buildlink3.mk"
.include	"../../devel/boost-libs/buildlink3.mk"
.include	"../../devel/libusb1/buildlink3.mk"
.include	"../../devel/orc/buildlink3.mk"

# \todo Clearly threre is some ordering scheme.  Explain it.

.include	"../../ham/uhd/buildlink3.mk"
.include	"../../lang/python/application.mk"
#.include	"../../lang/python/extension.mk"

.include	"../../ham/rtl-sdr/buildlink3.mk"
.include	"../../ham/libmirisdr/buildlink3.mk"
.include	"../../ham/osmo-sdr/buildlink3.mk"
# \todo Re-enable gr-fcdproplus when it works, or optionize it.
# gr-fcdproplus does not build at the moment
#.include	"../../ham/gr-fcdproplus/buildlink3.mk"
.include	"../../ham/hackrf/buildlink3.mk"
.include	"../../ham/soapy-sdr/buildlink3.mk"

BUILDLINK_API_DEPENDS.gnuradio-core+=	gnuradio-core>=3.8
.include	"../../wip/gnuradio-core/buildlink3.mk"
.include	"../../wip/gnuradio-uhd/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
