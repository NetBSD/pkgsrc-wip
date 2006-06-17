# $NetBSD: Makefile,v 1.2 2006/06/17 19:04:47 jeremy-c-reed Exp $
#

DISTNAME=		libXp-1.0.0
CATEGORIES=		x11 print
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/releases/individual/lib/
COMMENT=		X Print Service Extension Library

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		LIB_MAN_SUFFIX=3
PKGCONFIG_OVERRIDE+=	xp.pc.in

.include "../../mk/bsd.prefs.mk"
# TODO: check this -- this was needed for 3.99 but not 2.0.2
.if ${OPSYS} == "NetBSD" && !empty(OS_VERSION:M[3]*)
CFLAGS+=		-D_POSIX_THREAD_SAFE_FUNCTIONS
.endif

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "none"
# XXX need to test this and see how PLIST changes
CONFIGURE_ARGS+=	--disable-xthreads
.endif

.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../wip/printproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
