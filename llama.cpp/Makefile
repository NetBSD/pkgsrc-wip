# $NetBSD$

.include "../../wip/llama.cpp/Makefile.common"

CATEGORIES=	devel
DISTFILES=	${DEFAULT_DISTFILES} llama-b${LLAMA_BUILD_NUMBER}-ui.tar.gz
SITES.llama-b${LLAMA_BUILD_NUMBER}-ui.tar.gz=	https://github.com/ggml-org/llama.cpp/releases/download/b${LLAMA_BUILD_NUMBER}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ggerganov/llama.cpp/
COMMENT=	LLM inference in C/C++
LICENSE=	mit

USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++17

PKGCONFIG_OVERRIDE+=	cmake/llama.pc.in

CMAKE_CONFIGURE_ARGS+=	-DLLAMA_BUILD_NUMBER=${LLAMA_BUILD_NUMBER}
CMAKE_CONFIGURE_ARGS+=	-DLLAMA_BUILD_COMMIT=${LLAMA_BUILD_COMMIT}
CMAKE_CONFIGURE_ARGS+=	-DLLAMA_BUILD_TESTS=NO

.include "options.mk"

post-extract:
	${LN} -s ${WRKDIR}/llama-b${LLAMA_BUILD_NUMBER} ${WRKSRC}/tools/ui/dist

.include "../../www/curl/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
