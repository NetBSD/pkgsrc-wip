# $NetBSD$

GITHUB_PROJECT=	herbe
GITHUB_TAG=	refs/tags/1.0.0
DISTNAME=	1.0.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=dudik/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	kevin.bloom@posteo.net
HOMEPAGE=	https://github.com/dudik/herbe/
COMMENT=	Daemon-less notifications without D-Bus
LICENSE=	mit

WRKSRC=	${WRKDIR}/herbe-1.0.0

.include "../../mk/bsd.pkg.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
