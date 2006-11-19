# $NetBSD: Makefile,v 1.10 2006/11/19 11:46:53 thomasklausner Exp $

DISTNAME=	xorg-server-1.1.99.3
CATEGORIES=	x11
#MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/xserver/
# use snapshot
MASTER_SITES=	http://xorg.freedesktop.org/archive/development/individual/xserver/
EXTRACT_SUFX=	.tar.bz2

COMMENT=	Xorg X11 Server from modular X.org X11

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xorg-server.pc.in
USE_TOOLS+=	pkg-config
USE_TOOLS+=	gmake
USE_TOOLS+=	perl
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

BUILDLINK_API_DEPENDS.fixesproto+=	fixesproto>=4.0
BUILDLINK_API_DEPENDS.kbproto+=		kbproto>=1.0.3
BUILDLINK_API_DEPENDS.libXfixes+=	libXfixes>=4.0
BUILDLINK_API_DEPENDS.scrnsaverproto+=	scrnsaverproto>=1.1
BUILDLINK_API_DEPENDS.xkbui+=		xkbui>=1.0.2

# need mesa for glx and more
# maybe this should be a configure option?
.include "../../graphics/MesaLib/buildlink3.mk"

#.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/bigreqsproto/buildlink3.mk"
.include "../../x11/damageproto/buildlink3.mk"
.include "../../x11/evieext/buildlink3.mk"
.include "../../x11/fontsproto/buildlink3.mk"
.include "../../x11/glproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXfont/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXxf86misc/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../fonts/libfontenc/buildlink3.mk"
.include "../../x11/liblbxutil/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/libxkbui/buildlink3.mk"
.include "../../x11/recordproto/buildlink3.mk"
.include "../../x11/resourceproto/buildlink3.mk"
.include "../../x11/scrnsaverproto/buildlink3.mk"
.include "../../x11/trapproto/buildlink3.mk"
.include "../../x11/videoproto/buildlink3.mk"
.include "../../x11/xcmiscproto/buildlink3.mk"
.include "../../x11/xf86bigfontproto/buildlink3.mk"
.include "../../x11/xf86dgaproto/buildlink3.mk"
.include "../../x11/xf86driproto/buildlink3.mk"
.include "../../x11/xf86miscproto/buildlink3.mk"
.include "../../x11/xf86vidmodeproto/buildlink3.mk"
.include "../../x11/xineramaproto/buildlink3.mk"
.include "../../x11/xtrans/buildlink3.mk"
.include "../../x11/compositeproto/buildlink3.mk"
.include "../../x11/fixesproto/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/renderproto/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

# printproto
# xf86rushproto
# panoramixproto
# xpm
# xtst

.include "../../mk/bsd.pkg.mk"
