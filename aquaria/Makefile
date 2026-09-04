# $NetBSD$

DISTNAME=	Aquaria
PKGNAME=	aquaria-1.1.3
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=AquariaOSE/}
GITHUB_PROJECT=	Aquaria
GITHUB_TAG=	7377ea0a09a7691451e8c00e9a027ccfabeb2a06

MAINTAINER=	charlotte@NetBSD.org
COMMENT=	Aquaria Open Source Edition
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	gtar
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
WRKSRC=		${WRKDIR}/${DISTNAME}-${GITHUB_TAG}

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../devel/cmake/build.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
