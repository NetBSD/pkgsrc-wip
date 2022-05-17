# $NetBSD$

DISTNAME=	Aquaria
PKGNAME=	aquaria-1.1.3
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=AquariaOSE/}
GITHUB_PROJECT=	Aquaria
GITHUB_TAG=	84366ad533fb42d00f6645052b9e56f693b81a2c

MAINTAINER=	charlotte@NetBSD.org
COMMENT=	Aquaria Open Source Edition
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	gtar
USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
WRKSRC=		${WRKDIR}/${DISTNAME}-${GITHUB_TAG}

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
