# $NetBSD: Makefile,v 1.27 2006/04/21 16:31:58 jeremy-c-reed Exp $
#

# todo: do PLIST again
DISTNAME=		libX11-1.0.0
CATEGORIES=		x11 devel
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Base X libraries from modular Xorg X11

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

CONFIGURE_ARGS+=	--enable-man-pages=3
PKGCONFIG_OVERRIDE+=	x11.pc.in

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "none"
# XXX need to test this and see how PLIST changes
CONFIGURE_ARGS+=	--disable-xthreads
.else
CONFIGURE_ENV+=		XTHREADS_LIBS=${BUILDLINK_LDADD.pthread}
#CPPFLAGS+=		-DXUSE_MTSAFE_API -DXNO_MTSAFE_PWDAPI -D_REENTRANT
# -DXUSE_MTSAFE_API redefined? maybe not needed
.endif

.include "../../wip/bigreqsproto/buildlink3.mk"
.include "../../wip/inputproto/buildlink3.mk"
.include "../../wip/kbproto/buildlink3.mk"
.include "../../wip/libXau/buildlink3.mk"
.include "../../wip/libXdmcp/buildlink3.mk"
.include "../../wip/xcmiscproto/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../wip/xf86bigfontproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../wip/xtrans/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
