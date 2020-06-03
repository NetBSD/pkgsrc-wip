# $NetBSD$

DISTNAME=	libevhtp-${VERSION}
VERSION=	1.2.15

CATEGORIES=	www

MASTER_SITES=	${MASTER_SITE_GITHUB:=criticalstack/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	amoibos@gmail.com
HOMEPAGE=	https://github.com/ellzey/libevhtp
COMMENT=	Flexible replacement for libevent's httpd API
LICENSE=	modified-bsd

DIST_SUBDIR=	libevhtp

USE_CMAKE=	yes

USE_LANGUAGES+=	c99 c++

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
