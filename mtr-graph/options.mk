# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.mtr-graph
PKG_SUPPORTED_OPTIONS=	gtk
PKG_SUPPORTED_OPTIONS+=	inet6
PKG_SUPPORTED_OPTIONS+=	ipinfo
PKG_SUPPORTED_OPTIONS+=	libidn
PKG_SUPPORTED_OPTIONS+=	unicode
PKG_SUPPORTED_OPTIONS+=	sys-getopt
PKG_OPTIONS_OPTIONAL_GROUPS+=	graphcairo
PKG_OPTIONS_GROUP.graphcairo+=	graphcairo-xcb
PKG_OPTIONS_GROUP.graphcairo+=	graphcairo-xlib
PKG_SUGGESTED_OPTIONS+=	ipinfo
PKG_SUGGESTED_OPTIONS+=	unicode
PKG_SUGGESTED_OPTIONS+=	sys-getopt

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

.if !empty(PKG_OPTIONS:Mlibidn)
.include "../../devel/libidn/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libidn
.endif

.if !empty(PKG_OPTIONS:Municode)
CONFIGURE_ARGS+=	--with-unicode
.endif

.if !empty(PKG_OPTIONS:Msys-getopt)
CONFIGURE_ARGS+=	--with-sys-getopt
.endif
