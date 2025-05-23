# $NetBSD$

DISTNAME=	whisper.cpp-1.7.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ggerganov/}
GITHUB_PROJECT=	whisper.cpp
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/ggerganov/whisper.cpp/
COMMENT=	OpenAI's Whisper LLM inference in C/C++
LICENSE=	mit

USE_TOOLS+=		git pkg-config
USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++17

BLAS_INDEX64=		yes
BLAS_ACCEPTED=		openblas_pthread openblas_openmp
BLAS_C_INTERFACE=	yes

PKGCONFIG_OVERRIDE+=	cmake/whisper.pc.in
REPLACE_PYTHON+=	*.py */*.py */*/*.py

CMAKE_CONFIGURE_ARGS+=	-DWHISPER_BUILD_SERVER=ON
CMAKE_CONFIGURE_ARGS+=	-DWHISPER_FFMPEG=ON
CMAKE_CONFIGURE_ARGS+=	-DWHISPER_SDL2=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON
# XXX
#CMAKE_CONFIGURE_ARGS+=	-DGGML_BLAS=ON
#CMAKE_CONFIGURE_ARGS+=	-DGGML_BLAS_VENDOR=OpenBLAS
#CMAKE_CONFIGURE_ARGS+=	-DBLAS_LIBRARIES=${CBLAS_LIBS:Q}
CMAKE_CONFIGURE_ARGS+=	-DWHISPER_BUILD_TESTS=no
#CMAKE_CONFIGURE_ARGS+=	-DGGML_OPENCL_EMBED_KERNELS=OFF
#CMAKE_CONFIGURE_ARGS+=	-DGGML_OPENCL_PROFILING=OFF
#CMAKE_CONFIGURE_ARGS+=	-DGGML_OPENCL_USE_ADRENO_KERNELS=OFF

# XXX
SUBST_CLASSES+=		findblas
SUBST_STAGE.findblas=	pre-configure
SUBST_MESSAGE.findblas=	Fixing libpci soname
SUBST_FILES.findblas+=	ggml/src/ggml-blas/CMakeLists.txt
SUBST_SED.findblas+=	-e 's,DepBLAS openblas64,DepBLAS ${BLAS_PC},'

# avoid conflict with llama.cpp
post-install:
	${RM} ${DESTDIR}${PREFIX}/lib/libggml-cpu.so

#.include "../../devel/SDL2/buildlink3.mk"
.include "../../multimedia/ffmpeg6/buildlink3.mk"
.include "../../wip/llama.cpp/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../lang/python/application.mk"
.include "../../mk/blas.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
