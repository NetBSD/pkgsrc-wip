# $NetBSD$

DISTNAME=	libwebsockets-1.7.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=warmcat/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=warmcat/libwebsockets/}
COMMENT=	Lightweight C library for websocket clients and servers
# LGPL-2.1 with static link exceptions
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DLWS_WITHOUT_TESTAPPS=ON

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
