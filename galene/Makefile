# $NetBSD$

DISTNAME=	galene-1.2.1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=jech/}
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://galene.org/
COMMENT=	Videoconference server
LICENSE=	mit

MAKE_ENV+=	CGO_ENABLED=0

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
