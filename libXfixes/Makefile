# $NetBSD: Makefile,v 1.24 2006/10/29 08:32:46 shattered Exp $
#

DISTNAME=		libXfixes-4.0.1
CATEGORIES=		x11 devel
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Xfixes library and extension of X RandR from modular X.org

CONFLICTS+=		Xfixes-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
CONFIGURE_ENV+=		LIB_MAN_SUFFIX=3
PKGCONFIG_OVERRIDE+=	xfixes.pc.in

# needs version 4 which defines xXFixesHideCursorReq
BUILDLINK_API_DEPENDS.fixesproto+=	fixesproto>=4

.include "../../mk/bsd.prefs.mk"
.if defined(X11_TYPE) && ${X11_TYPE} == "native"
CONFIGURE_ENV+=		X_CFLAGS="-I${X11BASE}/include"
CONFIGURE_ENV+=		X_LIBS="-L${X11BASE}/lib -lX11"
.  include "../../mk/x11.buildlink3.mk"
.endif

.if defined(X11_TYPE) && ${X11_TYPE} == "modular-xorg"
.  include "../../wip/libX11/buildlink3.mk"
.endif

.include "../../x11/fixesproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
