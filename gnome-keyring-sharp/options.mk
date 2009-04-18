# $NetBSD: options.mk,v 1.1.1.1 2009/04/18 00:31:51 jihbed Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnome-keyring-sharp

PKG_SUPPORTED_OPTIONS=	ndesk-dbus
PKG_SUGGESTED_OPTIONS=    	ndesk-dbus

.include "../../mk/bsd.options.mk"

###
### Enable Ndesk-Dbus Support
###
.if !empty(PKG_OPTIONS:Mndesk-dbus)
CONFIGURE_ARGS+=	--enable-ndesk-dbus
.include "../../sysutils/ndesk-dbus/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ndesk-dbus
.endif
