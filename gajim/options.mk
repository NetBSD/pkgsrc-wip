# $NetBSD: options.mk,v 1.3 2009/01/07 22:52:52 tonnerre Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gajim
PKG_SUPPORTED_OPTIONS=	gtkspell dbus trayicon ssl avahi
PKG_SUGGESTED_OPTIONS=	gtkspell dbus trayicon ssl avahi

.include "../../mk/bsd.options.mk"

# gtkspell
.if !empty(PKG_OPTIONS:Mgtkspell)
.include "../../textproc/gtkspell/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gtkspell
PLIST_SUBST+=	GTKSPELL=""
.else
CONFIGURE_ARGS+=	--disable-gtkspell
PLIST_SUBST+=	GTKSPELL="@comment "
.endif

# dbus
.if !empty(PKG_OPTIONS:Mdbus)
.include "../../sysutils/py-dbus/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-remote
PLIST_SUBST+=	REMOTE=""
.else
CONFIGURE_ARGS+=	--disable-remote
PLIST_SUBST+=	REMOTE="@comment "
.endif

# trayicon
.if !empty(PKG_OPTIONS:Mtrayicon)
CONFIGURE_ARGS+=	--enable-trayicon
PLIST_SUBST+=	TRAYICON=""
.else
CONFIGURE_ARGS+=	--disable-trayicon
PLIST_SUBST+=	TRAYICON="@comment "
.endif

# ssl
.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/py-OpenSSL/buildlink3.mk"
.include "../../security/py-amkCrypto/buildlink3.mk"
.endif

# avahi
.if !empty(PKG_OPTIONS:Mavahi)
.include "../../net/avahi/buildlink3.mk"
.endif
