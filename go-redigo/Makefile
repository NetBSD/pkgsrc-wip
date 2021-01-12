# $NetBSD$

DISTNAME=	go-redigo-1.8.3
GITHUB_PROJECT=	redigo
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=gomodule/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/gomodule/redigo/
COMMENT=	Go client for Redis
LICENSE=	apache-2.0

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/gomodule/${GITHUB_PROJECT}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
