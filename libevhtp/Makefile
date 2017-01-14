# $NetBSD$
VERSION=	1.2.11
PKGNAME=	libevhtp-${VERSION}
CATEGORIES=	www
GITHUB_TAG=	${VERSION}
DISTNAME=	${GITHUB_TAG}
MASTER_SITES=	${MASTER_SITE_GITHUB:=ellzey/}

MAINTAINER=	amoibos@gmail.com
HOMEPAGE=	https://github.com/ellzey/libevhtp
COMMENT=	Flexible replacement for libevent's httpd API
LICENSE=	modified-bsd

DIST_SUBDIR=	libevhtp
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_CMAKE=	yes

USE_LANGUAGES+=	c99 c++

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
