# $NetBSD: Makefile,v 1.4 2004/02/17 02:55:36 blef Exp $
#

DISTNAME=	GNUnet-0.5.4a
CATEGORIES=	x11
MASTER_SITES=	http://www.ovmj.org/GNUnet/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.ovmj.org/GNUnet/
COMMENT=	Framework for secure p2p networking

BUILD_USES_MSGFMT=	yes

USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes

PTHREAD_OPTS=	require

CONFIGURE_ARGS+=        --without-gtk
CONFIGURE_ARGS+=        --with-crypto
CONFIGURE_ARGS+=	--with-gdbm=${BUILDLINK_PREFIX.gdbm}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

LDFLAGS+=	-lpthread -lintl

.include "../../mk/bsd.prefs.mk"
BUILD_DEFS+=	USE_INET6

.if defined(USE_INET6)
CONFIGURE_ARGS+=	--with-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.include "../../security/openssl/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../databases/gdbm/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
