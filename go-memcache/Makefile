# $NetBSD$

DISTNAME=	memcache-20190913
PKGNAME=	go-${DISTNAME}
GITHUB_PROJECT=	gomemcache
GITHUB_TAG=	a41fca8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=bradfitz/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/bradfitz/gomemcache/
COMMENT=	Go Memcached client library
LICENSE=	apache-2.0

GO_DIST_BASE=   ${GITHUB_PROJECT}-${GITHUB_TAG}*
GO_SRCPATH=     github.com/bradfitz/${GITHUB_PROJECT}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
