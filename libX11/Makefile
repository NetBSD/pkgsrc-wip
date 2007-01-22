# $NetBSD: Makefile,v 1.34 2007/01/22 09:40:09 bsadewitz Exp $
#

DISTNAME=	libX11-1.1.1
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/releases/individual/
COMMENT=	X11 protocol library (C bindings) from modular X.org


PKG_INSTALLATION_TYPES= overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--enable-man-pages=3

CPPFLAGS+=		-D_NETBSD_SOURCE

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	x11-xcb.pc.in
PKGCONFIG_OVERRIDE+=	x11.pc.in

.include "options.mk"

.include "../../x11/bigreqsproto/buildlink3.mk"
.include "../../x11/inputproto/buildlink3.mk"
.include "../../x11/kbproto/buildlink3.mk"
.include "../../wip/libXau/buildlink3.mk"
.include "../../wip/libXdmcp/buildlink3.mk"
.include "../../x11/xcmiscproto/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xf86bigfontproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/xtrans/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
