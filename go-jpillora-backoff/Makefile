# $NetBSD$

DISTNAME=	go-jpillora-backoff-1.0.0
GITHUB_PROJECT=	backoff
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GITHUB:=jpillora/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/jpillora/backoff/
COMMENT=	Simple backoff algorithm in Go
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/jpillora/backoff

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
