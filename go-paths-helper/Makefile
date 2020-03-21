# $NetBSD$

GITHUB_PROJECT=	go-paths-helper
GITHUB_TAG=	c3c98d1bf2e1069f60ab84bff3a2eb3c5422f3b0
DISTNAME=	${GITHUB_PROJECT}-${GITHUB_TAG}

PKGREVISION=	7
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_GITHUB:=arduino/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/arduino/go-paths-helper
COMMENT=	TODO: Short description of the package
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/arduino/go-paths-helper/



.include "../../lang/go/go-package.mk"


.include "../../mk/bsd.pkg.mk"
