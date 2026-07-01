# $NetBSD$

.include "../../wip/llama.cpp/Makefile.common"

PKGNAME=	${DISTNAME:S/-b/-${LLAMA_CPP_VAR}./}
CATEGORIES=	devel
# because 'b' is the second letter of the alphabet
LLAMA_CPP_VAR=	0.0.2
DISTFILES=	${DEFAULT_DISTFILES} llama-${GITHUB_TAG}-ui.tar.gz
SITES.llama-${GITHUB_TAG}-ui.tar.gz=	https://github.com/ggml-org/llama.cpp/releases/download/${GITHUB_TAG}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ggerganov/llama.cpp/
COMMENT=	LLM inference in C/C++
LICENSE=	mit

USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++17

PKGCONFIG_OVERRIDE+=	cmake/llama.pc.in

CMAKE_CONFIGURE_ARGS+=	-DLLAMA_BUILD_NUMBER=${LLAMA_BUILD_NUMBER}
CMAKE_CONFIGURE_ARGS+=	-DLLAMA_BUILD_COMMIT=${LLAMA_BUILD_COMMIT}
CMAKE_CONFIGURE_ARGS+=	-DLLAMA_BUILD_TESTS=NO
CMAKE_CONFIGURE_ARGS+=	-DLLAMA_USE_SYSTEM_GGML=YES

PRINT_PLIST_AWK+=	/lib\/.*\.so/ { sub(/${LLAMA_BUILD_NUMBER}/, "$${LLAMA_BUILD_NUMBER}") }
PLIST_SUBST+=		LLAMA_BUILD_NUMBER=${LLAMA_BUILD_NUMBER}

post-extract:
	${LN} -s ${WRKDIR}/llama-${GITHUB_TAG} ${WRKSRC}/tools/ui/dist

.include "../../www/curl/buildlink3.mk"
.include "../../wip/ggml/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
