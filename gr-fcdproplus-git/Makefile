# $NetBSD: Makefile,v 1.1 2014/10/06 15:10:50 makoto Exp $

DISTNAME=		gr-fcdproplus-3.7
CATEGORIES=		ham

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/dl1ksv/gr-fcdproplus
COMMENT=		Addon for funcube dongle pro+ to GNU Radio
LICENSE=		gnu-gpl-v2

GIT_REPOSITORIES=	master
GIT_REPO.master=	https://github.com/dl1ksv/gr-fcdproplus
GIT_MODULE.master=	gr-fcdproplus
GIT_ENV+=		GIT_SSL_NO_VERIFY=true

USE_LANGUAGES=		c c++
USE_TOOLS=		cmake
USE_CMAKE=		yes

WRKSRC=			${WRKDIR}/gr-fcdproplus
CXXFLAGS+=		-I${PREFIX}/include/libusb-1.0

# Suppress warning for developer
CMAKE_ARGS+=		-Wno-dev
CMAKE_ARGS+=		-DGNURADIO_RUNTIME_INCLUDE_DIRS=${PREFIX}/include
PLIST_SUBST+=		PYSITELIB=${PYSITELIB}

SUBST_CLASSES+=		libusb
SUBST_FILES.libusb+=	CMakeLists.txt
SUBST_STAGE.libusb=	pre-configure
SUBST_SED.libusb=	-e 's,@@PREFIX@@,${PREFIX},'
SUBST_MESSAGE.libusb=	Fix for "libusb.h not found"

.include	"../../wip/mk/git-package.mk"
# you need place after above line for now.
_GIT_FLAGS=		# set empty, --depth 1 seems harmfull

.include	"../../devel/boost-headers/buildlink3.mk"
.include	"../../devel/boost-libs/buildlink3.mk"
.include	"../../devel/libusb1/buildlink3.mk"
.include	"../../lang/python/application.mk"
.include	"../../lang/python/pyversion.mk"
.include 	"../../wip/gnuradio-core/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
