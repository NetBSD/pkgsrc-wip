# $NetBSD$

DISTNAME=	timego-20181230
PKGNAME=	go-${DISTNAME}
GITHUB_PROJECT=	timeago
GITHUB_TAG=	4e7d8c1f9a433881f64a7f87f51e494186857982
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GITHUB:=xeonx/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/xeonx/timeago/
COMMENT=	Go package for time formating based on current time
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/xeonx/${GITHUB_PROJECT}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
