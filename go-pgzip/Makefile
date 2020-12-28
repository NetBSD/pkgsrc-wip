# $NetBSD$

DISTNAME=	pgzip-1.2.5
PKGNAME=	go-${DISTNAME}
CATEGORIES=	archivers parallel
MASTER_SITES=	${MASTER_SITE_GITHUB:=klauspost/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/klauspost/pgzip/
COMMENT=	Go parallel gzip (de)compression
LICENSE=	mit

GO_SRCPATH=	github.com/klauspost/pgzip
GO_DIST_BASE=	${DISTNAME}

.include "../../devel/go-compress/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
