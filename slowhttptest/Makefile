# $NetBSD: Makefile,v 1.2 2015/06/10 13:43:17 ahp-nils Exp $

DISTNAME=	slowhttptest-1.6
CATEGORIES=	security
MASTER_SITES=	https://slowhttptest.googlecode.com/files/

MAINTAINER=	nils@NetBSD.org
HOMEPAGE=	https://code.google.com/p/slowhttptest/
COMMENT=	Tool implementing some Slow HTTP attacks
LICENSE=	apache-2.0

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
