# $NetBSD$

GITHUB_PROJECT=	gorilla-audio
GITHUB_TAG=	a3d6dbe5dd99f4ad29affb8d9a2d893ee30f5f3a
DISTNAME=	a3d6dbe5dd99f4ad29affb8d9a2d893ee30f5f3a
PKGNAME=	${GITHUB_PROJECT}-0.0.20201007
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=moon-chilled/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/moon-chilled/gorilla-audio/
COMMENT=	Library for playing real-time audio
LICENSE=	mit

WRKSRC=		${WRKDIR}/gorilla-audio-a3d6dbe5dd99f4ad29affb8d9a2d893ee30f5f3a
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DSYSTEM_LIBRARIES:BOOL=TRUE

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
