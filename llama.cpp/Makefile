# $NetBSD$

.include "../../wip/llama.cpp/Makefile.common"

PKGNAME=	${DISTNAME:S/-b/-${LLAMA_CPP_VAR}./}
CATEGORIES=	devel
LLAMA_CPP_VAR=	0.0.2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ggerganov/llama.cpp/
COMMENT=	LLM inference in C/C++
LICENSE=	mit

USE_TOOLS+=		git pkg-config
USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++17

BLAS_INDEX64=		yes
BLAS_ACCEPTED=		openblas_pthread #openblas_openmp
BLAS_C_INTERFACE=	yes

PKGCONFIG_OVERRIDE+=	cmake/llama.pc.in

CMAKE_CONFIGURE_ARGS+=	-DGGML_BLAS=ON
CMAKE_CONFIGURE_ARGS+=	-DGGML_BLAS_VENDOR=OpenBLAS
CMAKE_CONFIGURE_ARGS+=	-DBLAS_LIBRARIES=${CBLAS_LIBS:Q}
CMAKE_CONFIGURE_ARGS+=	-DLLAMA_BUILD_TESTS=no
CMAKE_CONFIGURE_ARGS+=	-DGGML_OPENCL_EMBED_KERNELS=OFF
CMAKE_CONFIGURE_ARGS+=	-DGGML_OPENCL_PROFILING=OFF
CMAKE_CONFIGURE_ARGS+=	-DGGML_OPENCL_USE_ADRENO_KERNELS=OFF

SUBST_CLASSES+=		findblas
SUBST_STAGE.findblas=	pre-configure
SUBST_MESSAGE.findblas=	Fixing libpci soname
SUBST_FILES.findblas+=	ggml/src/ggml-blas/CMakeLists.txt
SUBST_SED.findblas+=	-e 's,DepBLAS openblas64,DepBLAS ${BLAS_PC},'

.include "../../www/curl/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/blas.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
