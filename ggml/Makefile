# $NetBSD$

DISTNAME=	ggml-0.15.3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=ggml-org/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ggml-org/ggml/
COMMENT=	Tensor library for machine learning
LICENSE=	mit

DEPENDS+=	shaderc-[0-9]*:../../wip/shaderc

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

USE_CC_FEATURES=	c11
USE_CXX_FEATURES=	c++17

PKGCONFIG_OVERRIDE+=	ggml.pc.in

CMAKE_CONFIGURE_ARGS+=	-DGGML_BLAS=ON
CMAKE_CONFIGURE_ARGS+=	-DGGML_BLAS_VENDOR=OpenBLAS
CMAKE_CONFIGURE_ARGS+=	-DBLAS_LIBRARIES=${CBLAS_LIBS:Q}
CMAKE_CONFIGURE_ARGS+=	-DGGML_VULKAN=ON

BLAS_INDEX64=		yes
BLAS_ACCEPTED=		openblas_pthread #openblas_openmp
BLAS_C_INTERFACE=	yes

SUBST_CLASSES+=		findblas
SUBST_STAGE.findblas=	pre-configure
SUBST_MESSAGE.findblas=	Fixing libpci soname
SUBST_FILES.findblas+=	src/ggml-blas/CMakeLists.txt
SUBST_SED.findblas+=	-e 's,DepBLAS openblas64,DepBLAS ${BLAS_PC},'

.include "../../devel/cmake/build.mk"
.include "../../graphics/vulkan-headers/buildlink3.mk"
.include "../../graphics/vulkan-loader/buildlink3.mk"
.include "../../parallel/spirv-headers/buildlink3.mk"
.include "../../mk/blas.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
