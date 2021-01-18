# $NetBSD$

DISTNAME=	go-httphead-0.1.0
GITHUB_PROJECT=	httphead
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=gobwas/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/gobwas/httphead/
COMMENT=	Tiny HTTP header value parsing library in Go
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/gobwas/httphead/

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
