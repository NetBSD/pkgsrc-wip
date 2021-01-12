# $NetBSD$

DISTNAME=	douceur-aymerick-20180322
PKGNAME=	go-${DISTNAME}
GITHUB_PROJECT=	douceur
GITHUB_TAG=	f9e29746e1161076eae141dd235f5d98b546ec3e
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=aymerick/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/aymerick/douceur/
COMMENT=	Simple CSS parser and inliner in Go
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/aymerick/${GITHUB_PROJECT}

.include "../../net/go-net/buildlink3.mk"
.include "../../wip/go-cascadia/buildlink3.mk"
.include "../../wip/go-goquery/buildlink3.mk"
.include "../../wip/go-gorilla-css/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
