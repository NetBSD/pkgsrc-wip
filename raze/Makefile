# $NetBSD$

DISTNAME=	1.5.0
PKGNAME=	raze-${DISTNAME}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=ZDoom/}
GITHUB_PROJECT=	Raze
GITHUB_TAG=	1.5.0
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://raze.zdoom.org/
COMMENT=	Fork of the Build engine backed by GZDoom tech
#LICENSE=	build AND gnu-gpl-v2

WRKSRC=		${WRKDIR}/Raze-1.5.0
USE_CMAKE=	yes
USE_LANGUAGES=	c c++
CXXFLAGS+=	-D PKGSRC_RAZE_PATH='"${PREFIX}/share/games/raze"'

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
