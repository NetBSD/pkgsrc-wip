# $NetBSD$

DISTNAME=	Aquaria
PKGNAME=	aquaria-1.1.3
CATEGORIES=	games
GITHUB_TAG=	d8da8576e8321fd989cbb865c0e4d19d295a36b1
GITHUB_PROJECT=	Aquaria
MASTER_SITES=	${MASTER_SITE_GITHUB:=AquariaOSE/}
LICENSE=	gnu-gpl-v2

MAINTAINER=	cfkoch@edgebsd.org
COMMENT=	Aquaria Open Source Edition

EXTRACT_USING=	gtar
USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
WRKSRC=		${WRKDIR}/${DISTNAME}-${GITHUB_TAG}

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
