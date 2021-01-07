# $NetBSD$

DISTNAME=	lzw-20190829
PKGNAME=	go-${DISTNAME}
GITHUB_PROJECT=	lzw
GITHUB_TAG=	6f07a24e8650c51b71eb29219a1f243f91658cf4
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=hhrutter/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/hhrutter/lzw
COMMENT=	Extended version of compress/lzw
LICENSE=	2-clause-bsd

GO_SRCPATH=     github.com/hhrutter/lzw
GO_DIST_BASE=   ${GITHUB_PROJECT}-${GITHUB_TAG}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
