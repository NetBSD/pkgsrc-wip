# $NetBSD$

DISTNAME=	libwebsockets-1.7.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=warmcat/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/warmcat/libwebsockets/
COMMENT=	Lightweight C library for websocket clients and servers
# LGPL-2.1 with static link exceptions
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
