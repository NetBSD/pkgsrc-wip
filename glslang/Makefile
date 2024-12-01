# $NetBSD$

DISTNAME=	glslang-15.0.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=KhronosGroup/}

MAINTAINER=	triaxx@NetBSD.org
HOMEPAGE=	https://github.com/KhronosGroup/glslang/
COMMENT=	Front end for GLSL/ESSL, HLSL (partial) and SPIR-V generator
LICENSE=	modified-bsd AND 2-clause-bsd AND mit AND apache-2.0 AND \
		gnu-gpl-v3

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DALLOW_EXTERNAL_SPIRV_TOOLS=ON

.include "../../devel/cmake/build.mk"

.include "../../wip/spirv-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
