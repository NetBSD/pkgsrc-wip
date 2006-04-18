# $NetBSD: Makefile,v 1.5 2006/04/18 18:27:51 jeremy-c-reed Exp $

DISTNAME=	xorg-server-0.99.2
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/X11R7.0-RC1/xserver/
EXTRACT_SUFX=	.tar.bz2

COMMENT=	Xorg X11 Server from modular X.org X11

GNU_CONFIGURE=	YES
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xorg-server.pc.in
USE_TOOLS+=	pkg-config

#.include "../../devel/zlib/buildlink3.mk"
.include "../../wip/bigreqsproto/buildlink3.mk"
.include "../../x11/compositeproto/buildlink3.mk"
.include "../../wip/damageproto/buildlink3.mk"
.include "../../x11/fixesproto/buildlink3.mk"
.include "../../wip/fontsproto/buildlink3.mk"
.include "../../wip/libdrm/buildlink3.mk"
.include "../../wip/libfontenc/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/libXau/buildlink3.mk"
.include "../../wip/libXext/buildlink3.mk"
.include "../../wip/libXfixes/buildlink3.mk"
.include "../../wip/libXfont/buildlink3.mk"
.include "../../wip/libxkbfile/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
.include "../../wip/recordproto/buildlink3.mk"
.include "../../x11/renderproto/buildlink3.mk"
.include "../../wip/resourceproto/buildlink3.mk"
.include "../../wip/scrnsaverproto/buildlink3.mk"
.include "../../wip/videoproto/buildlink3.mk"
.include "../../wip/xcmiscproto/buildlink3.mk"
.include "../../wip/xextproto/buildlink3.mk"
.include "../../wip/xf86bigfontproto/buildlink3.mk"
.include "../../wip/xf86driproto/buildlink3.mk"
.include "../../wip/xf86miscproto/buildlink3.mk"
.include "../../wip/xf86vidmodeproto/buildlink3.mk"
.include "../../wip/xineramaproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../wip/xtrans/buildlink3.mk"

# xf86dgaproto xf86rushproto panoramixproto

# xkbui xxf86misc xxf86vm xaw7 xmu xt xpm x11

.include "../../mk/bsd.pkg.mk"
