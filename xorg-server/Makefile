# $NetBSD: Makefile,v 1.8 2006/10/05 15:54:34 jeremy-c-reed Exp $

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
.include "../../wip/bigreqsproto/buildlink3.mk"
.include "../../wip/damageproto/buildlink3.mk"
.include "../../wip/evieext/buildlink3.mk"
.include "../../wip/fontsproto/buildlink3.mk"
.include "../../wip/glproto/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/libXau/buildlink3.mk"
.include "../../wip/libXaw/buildlink3.mk"
.include "../../wip/libXext/buildlink3.mk"
.include "../../wip/libXfixes/buildlink3.mk"
.include "../../wip/libXfont/buildlink3.mk"
.include "../../wip/libXt/buildlink3.mk"
.include "../../wip/libXxf86misc/buildlink3.mk"
.include "../../wip/libXxf86vm/buildlink3.mk"
.include "../../wip/libdrm/buildlink3.mk"
.include "../../wip/libfontenc/buildlink3.mk"
.include "../../wip/liblbxutil/buildlink3.mk"
.include "../../wip/libxkbfile/buildlink3.mk"
.include "../../wip/libxkbui/buildlink3.mk"
.include "../../wip/recordproto/buildlink3.mk"
.include "../../wip/resourceproto/buildlink3.mk"
.include "../../wip/scrnsaverproto/buildlink3.mk"
.include "../../wip/trapproto/buildlink3.mk"
.include "../../wip/videoproto/buildlink3.mk"
.include "../../wip/xcmiscproto/buildlink3.mk"
.include "../../wip/xf86bigfontproto/buildlink3.mk"
.include "../../wip/xf86dgaproto/buildlink3.mk"
.include "../../wip/xf86driproto/buildlink3.mk"
.include "../../wip/xf86miscproto/buildlink3.mk"
.include "../../wip/xf86vidmodeproto/buildlink3.mk"
.include "../../wip/xineramaproto/buildlink3.mk"
.include "../../wip/xtrans/buildlink3.mk"
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
