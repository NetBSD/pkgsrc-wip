# $NetBSD$

DISTNAME=	go-backoff-4.1.0
PKGREVISION=	13
GITHUB_PROJECT=	backoff
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	# TODO: add primary category
MASTER_SITES=	${MASTER_SITE_GITHUB:=cenkalti/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cenkalti/backoff
COMMENT=	Exponential backoff algorithm in Go
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/cenkalti/backoff

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
