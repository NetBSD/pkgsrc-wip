# $NetBSD$

DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S/^g//}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=ZDoom/}
GITHUB_PROJECT=	gzdoom
GITHUB_TAG=	g4.11.3
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://zdoom.org/
COMMENT=	Zdoom game engine
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/gzdoom-${GITHUB_TAG}
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
CMAKE_CONFIGURE_ARGS+=	-DDL_LDFLAGS="${DL_LDFLAGS}"
CMAKE_CONFIGURE_ARGS+=	-DDL_LIBS="${DL_LIBS}"
CXXFLAGS+=	-D PKGSRC_DOOM_PATH='"${PREFIX}/share/games/doom"'

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../multimedia/libvpx/buildlink3.mk"
# .include "../../parallel/openmp/buildlink3.mk"
.include "../../wip/ZMusic/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
