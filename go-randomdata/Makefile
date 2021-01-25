# $NetBSD$

DISTNAME=	randomdata-1.2.0
PKGNAME=	go-${DISTNAME}
GITHUB_PROJECT=	go-randomdata
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=Pallinder/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/Pallinder/go-randomdata/
COMMENT=	Generator of random data for golang
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/Pallinder/${GITHUB_PROJECT}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
