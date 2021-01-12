# $NetBSD$

DISTNAME=	go-cache-20190904
GITHUB_PROJECT=	go-cache
GITHUB_TAG=	46f4078
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=patrickmn/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/patrickmn/go-cache/
COMMENT=	In-memory key:value store/cache library for Go
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}*
GO_SRCPATH=	github.com/patrickmn/${GITHUB_PROJECT}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
