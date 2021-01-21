# $NetBSD$

DISTNAME=	go-httprouter-1.3.0
GITHUB_PROJECT=	httprouter
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=julienschmidt/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/julienschmidt/httprouter/
COMMENT=	High performance HTTP request router that scales well
LICENSE=	2-clause-bsd

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/julienschmidt/${GITHUB_PROJECT}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
