# $NetBSD: Makefile,v 1.1.1.1 2003/07/18 02:50:08 poppnk Exp $
#

DISTNAME=	GNUnet-0.5.4a
CATEGORIES=	x11
MASTER_SITES=	http://www.ovmj.org/GNUnet/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.ovmj.org/GNUnet/
COMMENT=	Framework for secure p2p networking

BUILD_USES_MSGFMT=yes

USE_GMAKE=	yes

GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes
LIBTOOL_OVERRIDE=yes
PTHREAD_OPTS=	require
PKG_DEVELOPER=	yes

.include "../../mk/bsd.prefs.mk"
BUILD_DEFS+=	USE_INET6

CONFIGURE_ARGS+=	--without-gtk
CONFIGURE_ARGS+=	--with-gcrypt
CONFIGURE_ARGS+=	--with-crypto
.if defined(USE_INET6)
CONFIGURE_ARGS+=	--with-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.include "../../security/openssl/buildlink2.mk"
.include "../../security/libgcrypt/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
