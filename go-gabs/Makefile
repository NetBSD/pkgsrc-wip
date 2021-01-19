# $NetBSD$

DISTNAME=	go-gabs-2.6.0
GITHUB_PROJECT=	gabs
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Jeffail/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/Jeffail/gabs/
COMMENT=	For parsing, creating and editing unknown or dynamic JSON in Go
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/Jeffail/${GITHUB_PROJECT}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
