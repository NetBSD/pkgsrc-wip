# $NetBSD: Makefile,v 1.1 2014/10/06 15:10:50 makoto Exp $

# Do not delete until gr-funcube works as this has bits that are
# likely useful to steal.

DISTNAME=		gr-fcdproplus-3.7
CATEGORIES=		ham
GIT_REPO=		https://github.com/dl1ksv/gr-fcdproplus

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/dl1ksv/gr-fcdproplus
COMMENT=		Addon for funcube dongle pro+ to GNU Radio
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS+=		cmake
USE_CMAKE=		yes

CXXFLAGS+=		-I${PREFIX}/include/libusb-1.0

# Suppress warning for developer
CMAKE_CONFIGURE_ARGS+=		-Wno-dev
CMAKE_CONFIGURE_ARGS+=		-DGNURADIO_RUNTIME_INCLUDE_DIRS=${PREFIX}/include
PLIST_SUBST+=		PYSITELIB=${PYSITELIB}

SUBST_CLASSES+=		libusb
SUBST_FILES.libusb+=	CMakeLists.txt
SUBST_STAGE.libusb=	pre-configure
SUBST_SED.libusb=	-e 's,@@PREFIX@@,${PREFIX},'
SUBST_MESSAGE.libusb=	Fix for "libusb.h not found"

.include	"../../wip/mk/git-package.mk"

.include	"../../devel/boost-headers/buildlink3.mk"
.include	"../../devel/boost-libs/buildlink3.mk"
.include	"../../devel/libusb1/buildlink3.mk"
.include	"../../lang/python/application.mk"
.include	"../../lang/python/pyversion.mk"
.include 	"../../wip/gnuradio-core/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
