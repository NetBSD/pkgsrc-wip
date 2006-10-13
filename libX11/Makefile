# $NetBSD: Makefile,v 1.31 2006/10/13 13:28:47 jeremy-c-reed Exp $
#

DISTNAME=		libX11-1.0.3
CATEGORIES=		x11 devel
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Base X libraries from modular Xorg X11

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAKE_JOBS_SAFE=		no

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

CONFIGURE_ARGS+=	--enable-man-pages=3
PKGCONFIG_OVERRIDE+=	x11.pc.in

.include "../../mk/bsd.prefs.mk"

CHECK_X11_TYPE?=	yes

.if defined(CHECK_X11_TYPE) && !empty(CHECK_X11_TYPE:M[Yy][Ee][Ss])
.    if !defined(X11_TYPE) || empty(X11_TYPE:Mmodular-xorg)
PKG_FAIL_REASON+=	"X11_TYPE=modular-xorg is mandatory."
.    endif
.endif

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "none"
# XXX need to test this and see how PLIST changes
CONFIGURE_ARGS+=	--disable-xthreads
.else
CFLAGS+=		-D_POSIX_THREAD_SAFE_FUNCTIONS
#CONFIGURE_ENV+=		XTHREADS_LIBS=${BUILDLINK_LDADD.pthread}
#CPPFLAGS+=		-DXNO_MTSAFE_PWDAPI -D_REENTRANT
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
BUILDLINK_API_DEPENDS.xproto+=  xproto>=7.0.6
.include "../../x11/xproto/buildlink3.mk"
.include "../../wip/xtrans/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
