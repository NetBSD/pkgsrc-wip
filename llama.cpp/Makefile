# $NetBSD$

DISTNAME=	llama.cpp-${GITHUB_TAG}
PKGNAME=	${DISTNAME:S/-b/-0.0.2./}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ggerganov/}
GITHUB_TAG=	b3173

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ggerganov/llama.cpp/
COMMENT=	LLM inference in C/C++
LICENSE=	mit

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

BLAS_C_INTERFACE=	yes

PKGCONFIG_OVERRIDE+=	cmake/llama.pc.in
REPLACE_PYTHON+=	*.py */*.py */*/*.py

CMAKE_CONFIGURE_ARGS+=	-DLLAMA_BLAS=1
CMAKE_CONFIGURE_ARGS+=	-DBLAS_LIBRARIES=${CBLAS_LIBS:Q}
CMAKE_CONFIGURE_ARGS+=	-DLLAMA_BUILD_TESTS=no

.include "../../devel/cmake/build.mk"
.include "../../lang/python/application.mk"
.include "../../mk/blas.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
