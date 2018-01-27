# $NetBSD$

DISTNAME=	eventd-0.21.0
CATEGORIES=	net sysutils
MASTER_SITES=	https://www.eventd.org/download/eventd/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	sardemff7@eventd.org
HOMEPAGE=	https://www.eventd.org/
COMMENT=	Small daemon to act on remote or local events
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v3 AND mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	client/libeventc/pkgconfig/libeventc.pc.in
PKGCONFIG_OVERRIDE+=	client/libeventc-light/pkgconfig/libeventc-light.pc.in
PKGCONFIG_OVERRIDE+=	server/eventd/pkgconfig/eventd.pc.in
PKGCONFIG_OVERRIDE+=	server/libeventd/pkgconfig/libeventd.pc.in
PKGCONFIG_OVERRIDE+=	server/libeventd/pkgconfig/libeventd-protocol-json.pc.in
PKGCONFIG_OVERRIDE+=	server/libeventd-plugin/pkgconfig/libeventd-plugin.pc.in

CONFIGURE_ARGS+=	--disable-introspection
CONFIGURE_ARGS+=	--disable-websocket
CONFIGURE_ARGS+=	--disable-dns-sd
CONFIGURE_ARGS+=	--disable-ssdp
CONFIGURE_ARGS+=	--disable-nd-wayland
CONFIGURE_ARGS+=	--disable-im
CONFIGURE_ARGS+=	--disable-sound

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.40.0
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.12.0
# Needed for TLS support in evp
DEPENDS+=			glib-networking-[0-9]*:../../net/glib-networking
# Needed for SVG support in nd and notify
DEPENDS+=			librsvg-[0-9]*:../../graphics/librsvg

.include "../../textproc/libxslt/xsltproc-nonet.mk"
.include "../../devel/apr-util/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
