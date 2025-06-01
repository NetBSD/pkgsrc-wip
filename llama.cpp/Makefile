# $NetBSD$

DISTNAME=	llama.cpp-${GITHUB_TAG}
PKGNAME=	${DISTNAME:S/-b/-0.0.2./}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ggml-org/}
GITHUB_TAG=	b5541

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ggerganov/llama.cpp/
COMMENT=	LLM inference in C/C++
LICENSE=	mit

USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++17

DEPENDS+=	${PYPKGPREFIX}-torch>=2.2:../../math/py-torch
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.25:../../math/py-numpy
#DEPENDS+=	${PYPKGPREFIX}-gguf>=0.14:../../math/py-gguf
DEPENDS+=	${PYPKGPREFIX}-transformers>=4.35.2:../../math/py-transformers
DEPENDS+=	${PYPKGPREFIX}-protobuf>=4.21.0:../../devel/py-protobuf
DEPENDS+=	${PYPKGPREFIX}-sentencepiece>=0.1.98:../../textproc/py-sentencepiece

BLAS_INDEX64=		yes
BLAS_ACCEPTED=		openblas_pthread #openblas_openmp
BLAS_C_INTERFACE=	yes

PKGCONFIG_OVERRIDE+=	cmake/llama.pc.in
REPLACE_PYTHON+=	*.py */*.py */*/*.py

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
.include "../../lang/python/application.mk"
.include "../../mk/blas.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
