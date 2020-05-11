# $NetBSD$

DISTNAME=	libcanlock-3.2.0rc1
CATEGORIES=	news
MASTER_SITES=	http://micha.freeshell.org/libcanlock/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	http://micha.freeshell.org/libcanlock/
COMMENT=	Standalone RFC 8315 Netnews Cancel-Lock implementation
LICENSE=	mit AND modified-bsd

USE_LANGUAGES+=	c99

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

# For testing patch only, remove for release
USE_TOOLS+=	autoconf automake

TEST_TARGET=	test

# Recent NetBSD has a namespace clash with its implementation defined extensions
CFLAGS+=	-D_POSIX_C_SOURCE=200112L

CONFIGURE_ARGS+=	--disable-legacy-api
CONFIGURE_ARGS+=	--enable-pc-files
CONFIGURE_ARGS+=	--with-pkgconfigdir=${PREFIX}/lib/pkgconfig
# The header parsers are available as a separate package news/canlock-hp
CONFIGURE_ARGS+=	--disable-hp

# For testing patch only, remove for release
pre-configure:
	set -e; cd ${WRKSRC}; autoreconf -v -i -f

.include "../../mk/bsd.pkg.mk"
