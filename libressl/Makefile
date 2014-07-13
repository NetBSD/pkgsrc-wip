# $NetBSD: Makefile,v 1.1 2014/07/13 12:30:59 obache Exp $

DISTNAME=	libressl-2.0.1
CATEGORIES=	security
MASTER_SITES=	http://ftp.openbsd.org/pub/OpenBSD/LibreSSL/

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

CONFIGURE_ARGS+=	--with-openssldir=${PKG_SYSCONFDIR}

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
