# $NetBSD$

DISTNAME=	taisei-${GITHUB_TAG}
PKGNAME=	taisei-${VERSION}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=laochailan/}
VERSION=	1.0a
GITHUB_TAG=	v${VERSION}
LICENSE=	mit

MAINTAINER=	cfkoch@edgebsd.org
COMMENT=	Free clone of the touhou games
HOMEPAGE=	http://taisei-project.org/

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
USE_TOOLS+=	cmake

.include "../../audio/freealut/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
