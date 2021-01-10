# $NetBSD$

DISTNAME=	go-goquery-1.6.0
GITHUB_PROJECT=	goquery
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=PuerkitoBio/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/PuerkitoBio/goquery/
COMMENT=	Little like that j-thing, only in Go
LICENSE=	2-clause-bsd

GO_SRCPATH=	github.com/PuerkitoBio/goquery/
GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}

.include "../../net/go-net/buildlink3.mk"
.include "../../wip/go-cascadia/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
