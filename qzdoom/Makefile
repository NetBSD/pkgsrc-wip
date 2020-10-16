# $NetBSD$

DISTNAME=	qzdoom-4.4.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=madame-rachelle/}
GITHUB_TAG=	${DISTNAME:S/qzdoom-/g/}

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://qzdoom.drdteam.org/
COMMENT=	Continuation of dpJudas's truecolor software renderer for ZDoom
LICENSE=	gnu-gpl-v3

.include "../../mk/bsd.prefs.mk"

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
USE_CMAKE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/-/-g/}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../wip/ZMusic/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
