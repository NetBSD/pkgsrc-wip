# $NetBSD: options.mk,v 1.1 2014/09/25 14:05:46 yvs4sf Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mtr-graph
PKG_SUPPORTED_OPTIONS=	gtk
PKG_SUPPORTED_OPTIONS+=	inet6
PKG_SUPPORTED_OPTIONS+=	ipinfo
PKG_OPTIONS_OPTIONAL_GROUPS+=	graphcairo
PKG_OPTIONS_GROUP.graphcairo+=	graphcairo-xcb
PKG_OPTIONS_GROUP.graphcairo+=	graphcairo-xlib
PKG_SUGGESTED_OPTIONS=	inet6
PKG_SUGGESTED_OPTIONS+=	ipinfo
PKG_SUGGESTED_OPTIONS+=	graphcairo-xcb

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk)
USE_TOOLS+=		pkg-config
.include "../../x11/gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gtk
.endif

.if empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if empty(PKG_OPTIONS:Mipinfo)
CONFIGURE_ARGS+=	--without-ipinfo
.endif

.if !empty(PKG_OPTIONS:Mgraphcairo-xcb)
USE_TOOLS+=		pkg-config
.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
CONFIGURE_ARGS+=	--with-graphcairo-xcb
.else
.if !empty(PKG_OPTIONS:Mgraphcairo-xlib)
USE_TOOLS+=		pkg-config
.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
CONFIGURE_ARGS+=	--with-graphcairo-xlib
.endif
.endif
