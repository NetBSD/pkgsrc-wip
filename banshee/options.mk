# $NetBSD: options.mk,v 1.2 2014/08/03 22:16:38 thomasklausner Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.banshee
PKG_SUPPORTED_OPTIONS+=		gnome		# XXX complains in runtime
PKG_SUPPORTED_OPTIONS+=		mtp
PKG_SUPPORTED_OPTIONS+=		web boo daap

PKG_SUGGESTED_OPTIONS+=		gnome daap

.include "../../mk/bsd.options.mk"

PLIST_VARS+=			${PKG_SUPPORTED_OPTIONS}

.if !empty(PKG_OPTIONS:Mgnome)
PLIST.gnome=		yes
.else
CONFIGURE_ARGS+=	--disable-gnome
.endif

### Digital Audio Player (DAP) Support:

CONFIGURE_ARGS+=	--disable-appledevice	# XXX not there

.if !empty(PKG_OPTIONS:Mmtp)
PLIST.mtp=		yes
.include "../../devel/libmtp/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-mtp
.endif

### Extra Features:

.if !empty(PKG_OPTIONS:Mweb)
PLIST.web=		yes
.include "../../www/webkit24-gtk/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mboo)
.include "../../wip/boo/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-boo
.endif

.if !empty(PKG_OPTIONS:Mdaap)
PLIST.daap=		yes
.else
CONFIGURE_ARGS+=	--disable-daap		# XXX complains in runtime
.endif

CONFIGURE_ARGS+=	--disable-youtube	# XXX gdata-sharp >= 1.4
