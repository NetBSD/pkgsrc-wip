# $NetBSD$

DISTNAME=	libcanlock-3.3.0rc3
PKGNAME=	${DISTNAME:S/libcanlock/canlock-hp/}
CATEGORIES=	news
MASTER_SITES=	http://micha.freeshell.org/libcanlock/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	http://micha.freeshell.org/canlock-hp/
COMMENT=	Parsers for RFC 5536 message headers and RFC 8315 header fields
LICENSE=	mit

USE_TOOLS+=	lex yacc
USE_LANGUAGES+=	c99
USE_LIBTOOL=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-pc-files
CONFIGURE_ARGS+=	--with-pkgconfigdir=${PREFIX}/lib/pkgconfig

CONFIGURE_DIRS=	hp
BUILD_DIRS=	hp
TEST_TARGET=	test

.include "../../mk/bsd.pkg.mk"
