# $NetBSD$

DISTNAME=	wolfssl-4.3.0
CATEGORIES=	security
MASTER_SITES=	https://www.wolfssl.com/
EXTRACT_SUFX=	.zip

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://www.wolfssl.com/
COMMENT=	Embedded SSL C-Library
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking \
		--enable-dh \
		--enable-dsa \
		--enable-dtls \
		--enable-ecc \
		--enable-ipv6 \
		--enable-keygen \
		--enable-opensslextra \
		--enable-ripemd \
		--enable-sha512 \
		--enable-shared \
		--enable-sni \
		--enable-ssh \
		--enable-static \
		--enable-tls13 \
		--enable-tls13-draft18 \
		--enable-tls13-draft22 \
		--enable-tls13-draft23 \
		--enable-tls13-draft26 \
		--enable-tls13-draft28

USE_TOOLS+=	autoconf automake gawk gmake m4 pkg-config zip
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

INSTALL_TARGET=	install-strip

TEST_TARGET=	check

CHECK_PORTABILITY_SKIP=	certs/intermediate/genintcerts.sh configure

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} autoreconf -vif

.include "../../mk/bsd.pkg.mk"
