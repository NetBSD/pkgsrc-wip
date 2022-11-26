# $NetBSD: Makefile,v 1.77 2022/11/25 13:31:35 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-qt5
PKG_SUPPORTED_OPTIONS+=	dbus
PKG_SUGGESTED_OPTIONS+=	dbus

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		dbus
.if !empty(PKG_OPTIONS:Mdbus)
PLIST.dbus=		yes
.include "../../sysutils/dbus-python-common/buildlink3.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--no-python-dbus
.endif
