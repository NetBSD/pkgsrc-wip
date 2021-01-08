# $NetBSD$

DISTNAME=	go-brotli-1.0.1
GITHUB_PROJECT=	brotli
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=andybalholm/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/andybalholm/brotli/
COMMENT=	Pure Go Brotli encoder and decoder
LICENSE=	mit

GO_SRCPATH=	github.com/andybalholm/brotli
GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
