# $NetBSD$

DISTNAME=	bindata-assetfs-20201223
PKGNAME=	go-${DISTNAME}
GITHUB_PROJECT=	go-bindata-assetfs
GITHUB_TAG=	02daa69507fc3acc864aff07dff0d2460bf6511a
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=elazarl/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/elazarl/go-bindata-assetfs/
COMMENT=	Serves embedded files from jteeuwen/go-bindata with net/http
LICENSE=	2-clause-bsd

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/elazarl/${GITHUB_PROJECT}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
