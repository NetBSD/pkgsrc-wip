# $NetBSD$

DISTNAME=	master-775-b5d8120
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S/master-//:C/-[0-9a-z]*$//}
CATEGORIES=	devel graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=leejet/}
GITHUB_PROJECT=	stable-diffusion.cpp
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/leejet/stable-diffusion.cpp/
COMMENT=	Diffusion model inference in pure C/C++
LICENSE=	mit

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${DISTNAME}
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CMAKE_CONFIGURE_ARGS+=	-DSD_USE_SYSTEM_WEBP=ON
#CMAKE_CONFIGURE_ARGS+=	-DSD_USE_SYSTEM_GGML=ON
CMAKE_CONFIGURE_ARGS+=	-DSD_USE_SYSTEM_WEBM=ON

# upstream always uses the latest commit; for pkgsrc use git head
# commits as of packaging date, update them when updating this package
GITHUB_SUBMODULES+=	leejet ggml eced84c86f8b012c752c016f7fe789adea168e1e ggml
GITHUB_SUBMODULES+=	leejet sdcpp-webui c4bce3d6b3f236614cca21014f076083b7270ba8 examples/server/frontend

PKGCONFIG_OVERRIDE+=	cmake/stable-diffusion.pc.in

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/lib/libggml*

BUILDLINK_API_DEPENDS.libwebp+=	libwebp>=1.6.0nb2
.include "../../graphics/libwebp/buildlink3.mk"
BUILDLINK_API_DEPENDS.libwebm+=	libwebm>=1.0.0.32nb1
.include "../../wip/libwebm/buildlink3.mk"
# uses: #include "ggml/src/ggml-impl.h" so needs internal copy
#.include "../../math/ggml/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
