# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.mtr085

PKG_SUPPORTED_OPTIONS+=		dns
PKG_SUPPORTED_OPTIONS+=		idn
PKG_SUPPORTED_OPTIONS+=		unicode
PKG_SUPPORTED_OPTIONS+=		ipinfo
PKG_SUPPORTED_OPTIONS+=		inet6
PKG_SUPPORTED_OPTIONS+=		mpls
PKG_SUPPORTED_OPTIONS+=		graph

PKG_SUGGESTED_OPTIONS+=	dns
PKG_SUGGESTED_OPTIONS+=	idn
PKG_SUGGESTED_OPTIONS+=	unicode
PKG_SUGGESTED_OPTIONS+=	ipinfo
PKG_SUGGESTED_OPTIONS+=	inet6
PKG_SUGGESTED_OPTIONS+=	mpls

PKG_OPTIONS_LEGACY_OPTS=	libidn:idn

.include "../../mk/bsd.options.mk"

.if empty(PKG_OPTIONS:Minet6)
CMAKE_CONFIGURE_ARGS+=	-DIPV6=OFF
.endif

.if empty(PKG_OPTIONS:Mdns)
CMAKE_CONFIGURE_ARGS+=	-DDNS=OFF
.endif

.if empty(PKG_OPTIONS:Mmpls)
CMAKE_CONFIGURE_ARGS+=	-DMPLS=OFF
.endif

.if empty(PKG_OPTIONS:Mipinfo)
CMAKE_CONFIGURE_ARGS+=	-DIPINFO=OFF
.endif

.if !empty(PKG_OPTIONS:Mgraph)
.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DGRAPH=ON
.endif

.if !empty(PKG_OPTIONS:Midn)
.include "../../devel/libidn2/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DIDN=OFF
.endif

.if empty(PKG_OPTIONS:Municode)
CMAKE_CONFIGURE_ARGS+=	-DUNICODE=OFF
.endif
