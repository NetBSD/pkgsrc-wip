# $NetBSD$

DISTNAME=	go-flock-0.8.0
GITHUB_PROJECT=	flock
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=gofrs/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/gofrs/flock/
COMMENT=	Thread-safe file locking library in Go
LICENSE=	2-clause-bsd

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/gofrs/flock

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
