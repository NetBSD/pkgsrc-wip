# $NetBSD$

DISTNAME=	native-20200817
PKGNAME=	go-${DISTNAME}
GITHUB_PROJECT=	native
GITHUB_TAG=	b6b71def0850a2fbd7e6875f8e28217a48c5bcb4
CATEGORIES=	category
MASTER_SITES=	${MASTER_SITE_GITHUB:=josharian/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/josharian/native
COMMENT=	Package native provides easy access to native byte order
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/josharian/native

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
