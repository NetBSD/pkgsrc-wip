# $NetBSD$

DISTNAME=	randutil-0.1.0
PKGNAME=	go-${DISTNAME}
GITHUB_PROJECT=	randutil
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=pion/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/pion/randutil/
COMMENT=	Helper library for cryptographic and mathmatical randoms
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/pion/randutil

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
