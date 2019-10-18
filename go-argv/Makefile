# $NetBSD$

GITHUB_TAG=	v0.0.1
DISTNAME=	go-argv-0.0.1
PKGNAME=	go-argv-0.0.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=cosiner/}
GITHUB_PROJECT=	argv

MAINTAINER=	ng0@NetBSD.org
HOMEPAGE=	https://github.com/cosiner/argv
COMMENT=	Go library to split command line string into arguments array
LICENSE=	mit

GO_SRCPATH=	github.com/cosiner/argv
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG:S/v//}*

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
