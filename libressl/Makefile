# $NetBSD: Makefile,v 1.10 2015/04/04 14:01:28 krytarowski Exp $

DISTNAME=	libressl-2.1.6
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_OPENBSD:=LibreSSL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libressl.org/
COMMENT=	Secure Sockets Layer and cryptography libraries and tools
LICENSE=	openssl

CONFLICTS+=	openssl-[0-9]*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libcrypto.pc.in
PKGCONFIG_OVERRIDE+=	libssl.pc.in
PKGCONFIG_OVERRIDE+=	openssl.pc.in

PKG_SYSCONFSUBDIR=	openssl
CONFIGURE_ARGS+=	--with-openssldir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-enginesdir=${PREFIX}/lib/engines

# Added for 2.1.6 - remove for next stable version as it's fixed upstream
CPPFLAGS.NetBSD+=	-D_OPENBSD_SOURCE

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
