# $NetBSD: Makefile,v 1.20 2006/10/13 12:16:45 jeremy-c-reed Exp $
#

DISTNAME=		libXcursor-1.1.7
CATEGORIES=		x11 devel
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Client-side cursor loading library for X

CONFLICTS+=		xcursor-[0-9]*

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	xcursor.pc.in

.include "../../mk/bsd.prefs.mk"
.if defined(X11_TYPE) && ${X11_TYPE} == "native"
CONFIGURE_ENV+=         XCURSOR_CFLAGS="-I${X11BASE}/include"
CONFIGURE_ENV+=         XCURSOR_LIBS="-L${X11BASE}/lib -lX11"
.  include "../../mk/x11.buildlink3.mk"
.endif

.if defined(X11_TYPE) && ${X11_TYPE} == "modular-xorg"
.  include "../../wip/libX11/buildlink3.mk"
.endif

.include "../../wip/libXfixes/buildlink3.mk"
.include "../../wip/libXrender/buildlink3.mk"
.include "../../x11/fixesproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
