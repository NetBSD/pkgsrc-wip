# $NetBSD: Makefile,v 1.1.1.1 2005/10/17 18:54:04 jeremy-c-reed Exp $

DISTNAME=	xorg-server-0.99.1
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/X11R7.0-RC0/xserver/
EXTRACT_SUFX=	.tar.bz2

COMMENT=	Xorg X11 Server

GNU_CONFIGURE=	YES

#.include "../../devel/zlib/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/libXfont/buildlink3.mk"
.include "../../wip/libXext/buildlink3.mk"
.include "../../wip/libXau/buildlink3.mk"
.include "../../wip/xproto/buildlink3.mk"
.include "../../wip/xtrans/buildlink3.mk"
.include "../../wip/xextproto/buildlink3.mk"
.include "../../wip/libXfont/buildlink3.mk"
.include "../../wip/libXfixes/buildlink3.mk"

# randrproto renderproto damageproto xf86dgaproto xf86miscproto xf86rushproto xf86vidmodeproto xf86bigfontproto xkbfile recordproto resourceproto panoramixproto

.include "../../mk/bsd.pkg.mk"
