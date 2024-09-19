# $NetBSD$

DISTNAME=	go-securecookie-1.1.1
GITHUB_PROJECT=	securecookie
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=gorilla/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.gorillatoolkit.org/pkg/securecookie
COMMENT=	Encodes and decodes authenticated and optionally encrypted
LICENSE=	2-clause-bsd

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/gorilla/${GITHUB_PROJECT}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
