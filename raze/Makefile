# $NetBSD$

DISTNAME=	${GITHUB_TAG}
PKGNAME=	raze-${DISTNAME}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=ZDoom/}
GITHUB_PROJECT=	Raze
GITHUB_TAG=	1.9.1
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://raze.zdoom.org/
COMMENT=	Fork of the Build engine backed by GZDoom tech
#LICENSE=	build AND gnu-gpl-v2

WRKSRC=			${WRKDIR}/Raze-${GITHUB_TAG}
USE_CMAKE=		yes
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++17

CMAKE_CONFIGURE_ARGS+=	-DINSTALL_PK3_PATH=share/games/raze
CMAKE_CONFIGURE_ARGS+=	-DDYN_OPENAL=Off
CXXFLAGS+=	-D PKGSRC_RAZE_PATH='"${PREFIX}/share/games/raze"'

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
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
