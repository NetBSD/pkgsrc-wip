# $NetBSD$

DISTNAME=	g4.8.2
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S/^g//}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=ZDoom/}
GITHUB_PROJECT=	gzdoom
GITHUB_TAG=	g4.8.2
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://zdoom.org/
COMMENT=	Zdoom game engine
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/gzdoom-g4.8.2
USE_CMAKE=	yes
USE_LANGUAGES=	c c++
CXXFLAGS+=	-D PKGSRC_DOOM_PATH='"${PREFIX}/share/games/doom"'

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../multimedia/libvpx/buildlink3.mk"
# .include "../../parallel/openmp/buildlink3.mk"
.include "../../wip/ZMusic/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
