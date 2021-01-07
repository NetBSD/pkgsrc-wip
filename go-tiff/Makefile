# $NetBSD$

DISTNAME=	tiff-20190829
PKGNAME=	go-${DISTNAME}
PKGREVISION=	1
GITHUB_PROJECT=	tiff
GITHUB_TAG=	736cae8d0bc75b2649c1fc625160df41b66b9795
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=hhrutter/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/hhrutter/tiff
COMMENT=	Extended version of x/image/tiff
LICENSE=	2-clause-bsd

GO_SRCPATH=     github.com/hhrutter/tiff
GO_DIST_BASE=   ${GITHUB_PROJECT}-${GITHUB_TAG}

.include "../../graphics/go-image/buildlink3.mk"
.include "../../wip/go-lzw/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
