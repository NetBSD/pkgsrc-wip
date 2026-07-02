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
CMAKE_CONFIGURE_ARGS+=	-DSD_USE_SYSTEM_GGML=ON
# the libwebm source code provides neither .pc nor .cmake files for auto-detection
# so we need to use the git submodule
#CMAKE_CONFIGURE_ARGS+=	-DSD_USE_SYSTEM_WEBM=ON
#CMAKE_CONFIGURE_ARGS+=	-DWEBM_INCLUDE_DIR=${BUILDLINK_PREFIX.libwebm}/include
#CMAKE_CONFIGURE_ARGS+=	-DWEBM_LIBRARY=${BUILDLINK_PREFIX.libwebm}/lib/libwebm.so

# upstream always uses the latest commit; for pkgsrc use git head
# commits as of packaging date, update them when updating this package
GITHUB_SUBMODULES+=	leejet ggml 3af5f5760e19a96427f5f7a93b79cbdf3d4b265b ggml
GITHUB_SUBMODULES+=	leejet sdcpp-webui c4bce3d6b3f236614cca21014f076083b7270ba8 examples/server/frontend
GITHUB_SUBMODULES+=	webmproject libwebm 6184f4484a826724b5293837134ab9492261b941 thirdparty/libwebm

BUILDLINK_API_DEPENDS.libwebp+=	libwebp>=1.6.0nb2
.include "../../graphics/libwebp/buildlink3.mk"
#.include "../../wip/libwebm/buildlink3.mk"
.include "../../math/ggml/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
