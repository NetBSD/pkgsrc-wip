# $NetBSD$

DISTNAME=	go-concurrent-1.0.3
GITHUB_PROJECT=	concurrent
GITHUB_TAG=	${PKGVERSION_NOREV}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=modern-go/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/modern-go/concurrent/
COMMENT=	Concurrency utilities
LICENSE=	apache-2.0

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/modern-go/${GITHUB_PROJECT}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
