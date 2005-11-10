# $NetBSD: Makefile,v 1.2 2005/11/10 01:59:59 jeremy-c-reed Exp $

DISTNAME=	xorg-server-0.99.2
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/X11R7.0-RC1/xserver/
EXTRACT_SUFX=	.tar.bz2

COMMENT=	Xorg X11 Server from modular X.org X11

GNU_CONFIGURE=	YES
USE_TOOLS+=	pkg-config

#.include "../../devel/zlib/buildlink3.mk"
.include "../../wip/bigreqsproto/buildlink3.mk"
.include "../../wip/damageproto/buildlink3.mk"
.include "../../wip/fixesproto/buildlink3.mk"
.include "../../wip/fontsproto/buildlink3.mk"
.include "../../wip/libdrm/buildlink3.mk"
.include "../../wip/libfontenc/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/libXau/buildlink3.mk"
.include "../../wip/libXext/buildlink3.mk"
.include "../../wip/libXfixes/buildlink3.mk"
.include "../../wip/libXfont/buildlink3.mk"
.include "../../wip/randrproto/buildlink3.mk"
.include "../../wip/renderproto/buildlink3.mk"
.include "../../wip/xcmiscproto/buildlink3.mk"
.include "../../wip/xextproto/buildlink3.mk"
.include "../../wip/xf86bigfontproto/buildlink3.mk"
.include "../../wip/xf86driproto/buildlink3.mk"
.include "../../wip/xf86miscproto/buildlink3.mk"
.include "../../wip/xf86vidmodeproto/buildlink3.mk"
.include "../../wip/xproto/buildlink3.mk"
.include "../../wip/xtrans/buildlink3.mk"

# xf86dgaproto xf86rushproto panoramixproto

# scrnsaverproto resourceproto videoproto compositeproto recordproto xineramaproto xkbfile

.include "../../mk/bsd.pkg.mk"
