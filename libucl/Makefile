# $NetBSD: Makefile,v 1.2 2015/06/30 02:32:02 cfkoch Exp $

DISTNAME=	libucl-0.8.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=vstakhov/}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://github.com/vstakhov/libucl
COMMENT=	Universal configuration library parser
LICENSE=	2-clause-bsd

USE_LANGUAGES+=	c
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake autoreconf gmake pkg-config
GNU_CONFIGURE=	yes
TEST_TARGET=	check

# one test failure as of 0.8.1
# https://github.com/vstakhov/libucl/issues/244
pre-configure:
	cd ${WRKSRC} && sh ./autogen.sh

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
