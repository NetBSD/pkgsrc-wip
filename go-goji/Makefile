# $NetBSD$

DISTNAME=	go-goji-1.0.1
GITHUB_PROJECT=	goji
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=zenazn/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/zenazn/goji/
COMMENT=	Minimalistic web framework for Golang
LICENSE=	mit

GO_SRCPATH=	github.com/zenazn/goji
GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}

.include "../../wip/go-param/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
