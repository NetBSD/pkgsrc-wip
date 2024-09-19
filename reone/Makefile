# $NetBSD$

GITHUB_PROJECT=	reone
GITHUB_TAG=	0.19.0
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=seedhartha/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/seedhartha/reone/
COMMENT=	Game engine for running Knights of the Old Republic
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

#CMAKE_CONFIGURE_ARGS+=	-DUSE_EXTERNAL_GLM:BOOL=NO

.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libatomic/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
#.include "../../graphics/glm/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
