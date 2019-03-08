# $NetBSD$

GITHUB_PROJECT=	qtxqfsts
DISTNAME=	q2pro20190305
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=bsfd80/}
GITHUB_RELEASE=	20190228
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

DEPENDS+=	openal-soft-[0-9]*:../../audio/openal-soft
DEPENDS+=       SDL2-[0-9]*:../../devel/SDL2

MAINTAINER=	pkgls@gmx.net
HOMEPAGE=	https://github.com/bsfd80/qtxqfsts/
COMMENT=	Quake2 multiplayer orientated client
LICENSE=	gnu-gpl-v2

WRKSRC=	${WRKDIR}/q2pro-master

USE_LANGUAGES=	c
USE_TOOLS+=	gmake

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
