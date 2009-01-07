# $NetBSD: options.mk,v 1.4 2009/01/07 23:17:17 tonnerre Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gajim
PKG_SUPPORTED_OPTIONS=	avahi dbus gnome gnome-keyring gtkspell ssl trayicon
PKG_SUGGESTED_OPTIONS=	avahi dbus gtkspell ssl trayicon

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
DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
.include "../../security/py-amkCrypto/buildlink3.mk"
.endif

# avahi
.if !empty(PKG_OPTIONS:Mavahi)
.include "../../net/avahi/buildlink3.mk"
.endif

# gnome
.if !empty(PKG_OPTIONS:Mgnome)
.include "../../x11/py-gnome2/buildlink3.mk"
.endif

# avahi
.if !empty(PKG_OPTIONS:Mgnome-keyring)
.include "../../x11/py-gnome2-desktop/buildlink3.mk"
.endif
