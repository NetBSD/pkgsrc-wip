# $NetBSD$

DISTNAME=	go-resty-2.3.0
GITHUB_PROJECT=	resty
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=go-resty/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/go-resty/resty/
COMMENT=	Simple HTTP and REST client library for Go
LICENSE=	mit

EXTRACT_USING=	bsdtar

GO_SRCPATH=	github.com/go-resty/resty/
GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}

.include "../../net/go-net/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
