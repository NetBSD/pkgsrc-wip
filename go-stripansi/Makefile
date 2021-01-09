# $NetBSD$

DISTNAME=	stripansi-20180116
PKGNAME=	go-${DISTNAME}
GITHUB_PROJECT=	stripansi
GITHUB_TAG=	5a71ef0e047df0427e87a79f27009029921f1f9b
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=acarl005/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/acarl005/stripansi/
COMMENT=	Go package for removing ANSI color escape codes from strings
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/acarl005/${GITHUB_PROJECT}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
