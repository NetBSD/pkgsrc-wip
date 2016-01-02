# $NetBSD: Makefile,v 1.12 2015/04/12 00:10:27 krytarowski Exp $

DISTNAME=	libressl-2.2.5
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_OPENBSD:=LibreSSL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libressl.org/
COMMENT=	Secure Sockets Layer and cryptography libraries and tools
LICENSE=	openssl

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libcrypto.pc.in
PKGCONFIG_OVERRIDE+=	libssl.pc.in
PKGCONFIG_OVERRIDE+=	openssl.pc.in

LIBRESSL_PREFIX=	${PREFIX}/${PKGBASE}

PKG_SYSCONFSUBDIR=	${PKGBASE}
GNU_CONFIGURE_PREFIX=	${LIBRESSL_PREFIX}
CONFIGURE_ARGS+=	--with-openssldir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-enginesdir=${LIBRESSL_PREFIX}/lib/engines

# Added for 2.1.6 - remove for next stable version as it's fixed upstream
CPPFLAGS.NetBSD+=	-D_OPENBSD_SOURCE

# Handle subprefix
LDFLAGS+=		${COMPILER_RPATH_FLAG}${LIBRESSL_PREFIX:Q}/lib

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
