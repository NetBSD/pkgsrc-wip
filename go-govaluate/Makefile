# $NetBSD$

DISTNAME=	govaluate-3.0.0
PKGNAME=	go-${DISTNAME}
GITHUB_PROJECT=	govaluate
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Knetic/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/Knetic/govaluate/
COMMENT=	Arbitrary expression evaluation for golang
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/Knetic/${GITHUB_PROJECT}

USE_TOOLS+=	bash

REPLACE_BASH+=	Knetic/govaluate/test.sh


.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
