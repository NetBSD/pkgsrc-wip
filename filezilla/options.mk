# $NetBSD: options.mk,v 1.1 2009/04/07 14:34:42 tnn2 Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.filezilla
PKG_SUPPORTED_OPTIONS+=		dbus
PKG_SUGGESTED_OPTIONS+=		dbus

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		dbus

.if !empty(PKG_OPTIONS:Mdbus)
CONFIGURE_ARGS+=	--with-dbus
PLIST.dbus=		yes
.  include "../../sysutils/dbus/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-dbus
.endif
