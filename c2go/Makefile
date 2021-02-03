# $NetBSD$

DISTNAME=	c2go-0.26.7
GITHUB_PROJECT=	c2go
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=elliotchance/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/elliotchance/c2go/
COMMENT=	Tool for transpiling C to Go
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/elliotchance/c2go

.include "../../devel/go-tools/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
