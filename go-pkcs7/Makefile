# $NetBSD$

DISTNAME=	pkcs7-20200128
PKGNAME=	go-${DISTNAME}
DIST_SUBDIR=	${GITHUB_PROJECT}
GITHUB_PROJECT=	pkcs7
GITHUB_TAG=	432b2356ecb18209c1cec25680b8a23632794f21
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=mozilla-services/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/mozilla-services/pkcs7/
COMMENT=	Implements a subset of PKCS#7/Cryptographic
LICENSE=	mit

GO_DIST_BASE=   ${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=     github.com/mozilla-services/${GITHUB_PROJECT}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
