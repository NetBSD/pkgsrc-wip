# $NetBSD: Makefile,v 1.10 2006/10/29 08:32:46 shattered Exp $
#

DISTNAME=		libXrandr-1.1.1
CATEGORIES=		x11 devel
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X RandR Library from X.org

CONFLICTS+=		Xrandr-[0-9]*

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ENV+=		LIB_MAN_SUFFIX=3
PKGCONFIG_OVERRIDE+=	xrandr.pc.in

.include "../../mk/bsd.prefs.mk"
.if defined(X11_TYPE) && ${X11_TYPE} == "native"
CONFIGURE_ENV+=		X_CFLAGS="-I${X11BASE}/include"
CONFIGURE_ENV+=		X_LIBS="-L${X11BASE}/lib -lX11"
CONFIGURE_ENV+=		RANDR_CFLAGS="-I${BUILDLINK_PREFIX.Xrender}/include"
CONFIGURE_ENV+=		RANDR_LIBS="-L${BUILDLINK_PREFIX.Xrender}/lib -lX11"
.  include "../../mk/x11.buildlink3.mk"
.endif

.if defined(X11_TYPE) && ${X11_TYPE} == "modular-xorg"
.  include "../../wip/libX11/buildlink3.mk"
.  include "../../wip/libXext/buildlink3.mk"
.endif

.include "../../wip/libXrender/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/renderproto/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
