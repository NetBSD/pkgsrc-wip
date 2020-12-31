# $NetBSD$

GITHUB_PROJECT=	entityx
GITHUB_TAG=	1.3.0
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=alecthomas/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/alecthomas/entityx/
COMMENT=	Fast, type-safe C++ Entity-Component system
LICENSE=	mit

WRKSRC=		${WRKDIR}/entityx-${GITHUB_TAG}
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	entityx.pc.in

.include "../../mk/bsd.pkg.mk"
