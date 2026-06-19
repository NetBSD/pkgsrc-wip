# $NetBSD$

DISTNAME=	master-709-92a3b73
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S/master-//:C/-[0-9a-z]*$//}
CATEGORIES=	devel graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=leejet/}
GITHUB_PROJECT=	stable-diffusion.cpp
GITHUB_TAG=	master-709-92a3b73

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/leejet/stable-diffusion.cpp/
COMMENT=	Diffusion model inference in pure C/C++
LICENSE=	mit

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${DISTNAME}
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CMAKE_CONFIGURE_ARGS+=	-DSD_USE_SYSTEM_WEBP=ON
CMAKE_CONFIGURE_ARGS+=	-DGGML_BLAS=ON
CMAKE_CONFIGURE_ARGS+=	-DGGML_BLAS_VENDOR=OpenBLAS
CMAKE_CONFIGURE_ARGS+=	-DBLAS_LIBRARIES=${CBLAS_LIBS:Q}
# the libwebm source code provides neither .pc nor .cmake files for auto-detection
# so we need to use the git submodule
#CMAKE_CONFIGURE_ARGS+=	-DSD_USE_SYSTEM_WEBM=ON
#CMAKE_CONFIGURE_ARGS+=	-DWEBM_INCLUDE_DIR=${BUILDLINK_PREFIX.libwebm}/include
#CMAKE_CONFIGURE_ARGS+=	-DWEBM_LIBRARY=${BUILDLINK_PREFIX.libwebm}/lib/libwebm.so

BLAS_INDEX64=		yes
BLAS_ACCEPTED=		openblas_pthread #openblas_openmp
BLAS_C_INTERFACE=	yes

SUBST_CLASSES+=		findblas
SUBST_STAGE.findblas=	pre-configure
SUBST_MESSAGE.findblas=	Fixing libpci soname
SUBST_FILES.findblas+=	ggml/src/ggml-blas/CMakeLists.txt
SUBST_SED.findblas+=	-e 's,DepBLAS openblas64,DepBLAS ${BLAS_PC},'

# upstream always uses the latest commit; for pkgsrc use git head
# commits as of packaging date, update them when updating this package
GITHUB_SUBMODULES+=	leejet ggml 3af5f5760e19a96427f5f7a93b79cbdf3d4b265b ggml
GITHUB_SUBMODULES+=	leejet sdcpp-webui c4bce3d6b3f236614cca21014f076083b7270ba8 examples/server/frontend
GITHUB_SUBMODULES+=	webmproject libwebm 6184f4484a826724b5293837134ab9492261b941 thirdparty/libwebm

# didn't find the proper place in CMakeLists.txt to disable installing this library
post-install:
	${RM} ${DESTDIR}${PREFIX}/lib/libggml-blas.a
	${RM} ${DESTDIR}${PREFIX}/lib/libggml-cpu.a

.include "../../graphics/libwebp/buildlink3.mk"
#.include "../../wip/libwebm/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/blas.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
