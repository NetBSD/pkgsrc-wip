# $NetBSD$

DISTNAME=	onnxruntime-1.30.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=microsoft/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTFILES=	${DEFAULT_DISTFILES} eigen-3.4.0_p20250216.tar.gz
SITES.eigen-3.4.0_p20250216.tar.gz=	-https://github.com/eigen-mirror/eigen/archive/1d8b82b0740839c0de7f1242a3585e3390ff5f33.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/microsoft/onnxruntime/
COMMENT=	Cross-platform, high performance ML inferencing and training accelerator
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CONFIGURE_DIR=	cmake

CMAKE_ARGS+=	-DFETCHCONTENT_SOURCE_DIR_EIGEN3="${WRKDIR}/eigen-1d8b82b0740839c0de7f1242a3585e3390ff5f33"
#CMAKE_ARGS+=	-Donnxruntime_BUILD_SHARED_LIB=off
CMAKE_ARGS+=	-Donnxruntime_BUILD_UNIT_TESTS=off

#do-build:
#	cd ${WRKSRC} && ${PYTHONBIN} ${WRKSRC}/tools/ci_build/build.py --build_dir ${WRKSRC}/build/Linux

.include "../../devel/abseil/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/flatbuffers/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../devel/re2/buildlink3.mk"
.include "../../sysutils/cpuinfo/buildlink3.mk"
.include "../../textproc/nlohmann-json/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
