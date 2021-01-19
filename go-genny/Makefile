# $NetBSD$

DISTNAME=	go-genny-20200409
GITHUB_PROJECT=	genny
GITHUB_TAG=	3e22f1a
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=cheekybits/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/cheekybits/genny/
COMMENT=	Elegant generics for Go
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}*
GO_SRCPATH=	github.com/cheekybits/genny

.include "../../devel/go-mod/buildlink3.mk"
.include "../../devel/go-tools/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
