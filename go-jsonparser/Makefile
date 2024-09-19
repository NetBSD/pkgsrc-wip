# $NetBSD$

DISTNAME=	go-jsonparser-1.1.0
GITHUB_PROJECT=	jsonparser
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=buger/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/buger/jsonparser/
COMMENT=	JSON parser for Go that does not require schema
LICENSE=	2-clause-bsd

GO_SRCPATH=	github.com/buger/jsonparser
GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
