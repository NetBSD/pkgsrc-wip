# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.pounce

PKG_SUPPORTED_OPTIONS=	palaver pounce-notify
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	palaver pounce-notify

# Adds support for Palaver push notifications with pounce-palaver
.if !empty(PKG_OPTIONS:Mpalaver)
.include "../../www/curl/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-palaver
PLIST.palaver=		yes
.endif

# Builds pounce-notify which runs a command on notification
.if !empty(PKG_OPTIONS:Mpounce-notify)
CONFIGURE_ARGS+=	--enable-notify
PLIST.pounce-notify=	yes
.endif
