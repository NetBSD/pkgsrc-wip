# $NetBSD$

DISTNAME=	go-gorilla-mux-1.8.0
GITHUB_PROJECT=	mux
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=gorilla/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/gorilla/mux/
COMMENT=	Powerful HTTP router and URL matcher for building Go web servers
LICENSE=	2-clause-bsd

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/gorilla/${GITHUB_PROJECT}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
