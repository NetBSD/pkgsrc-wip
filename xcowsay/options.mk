# $NetBSD: options.mk,v 1.2 2010/01/16 20:34:54 leot1990 Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.xcowsay
PKG_SUPPORTED_OPTIONS=		dbus

.include "../../mk/bsd.options.mk"

#
# D-BUS support
#
.if !empty(PKG_OPTIONS:Mdbus)
CONFIGURE_ARGS+=	--enable-dbus
.  include "../../sysutils/dbus-glib/buildlink3.mk"
.endif
