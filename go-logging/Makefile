# $NetBSD$

DISTNAME=	logging-20201216
PKGNAME=	go-${DISTNAME}
GITHUB_PROJECT=	logging
GITHUB_TAG=	f86d3277e5bc6376c4331ba848b332086e53f06e
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=pion/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://pion.ly/
COMMENT=	The logging library used by Pion
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/pion/logging

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
