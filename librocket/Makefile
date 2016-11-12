# $NetBSD$

DISTNAME=	libRocket
PKGNAME=	librocket-${VERSION}
VERSION=	1.3.0.0
GITHUB_TAG=	release-${PKGVERSION_NOREV}
MASTER_SITES=	${MASTER_SITE_GITHUB:=libRocket/}
CATEGORIES=	games

HOMEPAGE=	http://librocket.com/
COMMENT=	The HTML/CSS user interface library
LICENSE=	mit

EXTRACT_USING=	gtar
USE_CMAKE=	yes
USE_LANGUAGES+=	c c++

WRKSRC=		${WRKDIR}/${DISTNAME}-${GITHUB_TAG}/Build

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
