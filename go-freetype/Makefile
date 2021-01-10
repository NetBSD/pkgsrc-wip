# $NetBSD$

DISTNAME=	freetype-20170609
PKGNAME=	go-${DISTNAME}
GITHUB_PROJECT=	freetype
GITHUB_TAG=	e2365dfdc4a05e4b8299a783240d4a7d5a65d4e4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=golang/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/golang/freetype/
COMMENT=	The Freetype font rasterizer in the Go programming language
LICENSE=	gnu-gpl-v2

GO_DIST_BASE=   ${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=     github.com/golang/${GITHUB_PROJECT}

USE_TOOLS+= bash

REPLACE_BASH+=	testdata/make-other-hinting-txts.sh

.include "../../graphics/go-image/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
