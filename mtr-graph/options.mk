# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.mtr-graph
PKG_SUPPORTED_OPTIONS=		inet6
PKG_SUPPORTED_OPTIONS+=		mpls
PKG_SUPPORTED_OPTIONS+=		dns
PKG_SUPPORTED_OPTIONS+=		idn
PKG_SUPPORTED_OPTIONS+=		unicode
PKG_SUPPORTED_OPTIONS+=		ipinfo
PKG_OPTIONS_OPTIONAL_GROUPS+=	graphcairo
PKG_OPTIONS_GROUP.graphcairo+=	graphcairo-xcb
PKG_OPTIONS_GROUP.graphcairo+=	graphcairo-xlib
PKG_SUGGESTED_OPTIONS+=		mpls
PKG_SUGGESTED_OPTIONS+=		dns
PKG_SUGGESTED_OPTIONS+=		unicode
PKG_SUGGESTED_OPTIONS+=		ipinfo
PKG_OPTIONS_LEGACY_OPTS=	libidn:idn

.include "../../mk/bsd.options.mk"

.if empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if empty(PKG_OPTIONS:Mdns)
CONFIGURE_ARGS+=	--disable-dns
.endif

.if empty(PKG_OPTIONS:Mmpls)
CONFIGURE_ARGS+=	--without-mpls
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
.  if !empty(PKG_OPTIONS:Mgraphcairo-xlib)
USE_TOOLS+=		pkg-config
.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
CONFIGURE_ARGS+=	--with-graphcairo-xlib
.  endif
.endif

.if !empty(PKG_OPTIONS:Midn)
.include "../../devel/libidn/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libidn
.endif

.if !empty(PKG_OPTIONS:Municode)
CONFIGURE_ARGS+=	--with-unicode
.endif

