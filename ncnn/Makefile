# $NetBSD$

DISTNAME=	ncnn
GITHUB_TAG=	20240820
PKGNAME=	${DISTNAME}-${GITHUB_TAG}
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Tencent/}

MAINTAINER=	triaxx@NetBSD.org
HOMEPAGE=	https://github.com/Tencent/ncnn/
COMMENT=	Neural network inference computing framework
LICENSE=	modified-bsd AND zlib AND 2-clause-bsd

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DNCNN_BUILD_TESTS=ON
CMAKE_CONFIGURE_ARGS+=	-DNCNN_SYSTEM_GLSLANG=ON
CMAKE_CONFIGURE_ARGS+=	-DNCNN_VULKAN=ON

.include "../../devel/cmake/build.mk"

.include "../../graphics/opencv/buildlink3.mk"
.include "../../wip/vulkan-loader/buildlink3.mk"
BUILDLINK_FILES.glslang+=	bin/glslang bin/spirv-remap
.include "../../wip/glslang/buildlink3.mk"
.include "../../parallel/spirv-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
