# $NetBSD: options.mk,v 1.1 2010/01/01 05:36:03 phonohawk Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.qmpdclient
PKG_SUPPORTED_OPTIONS=	dbus

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdbus)
.include "../../x11/qt4-qdbus/buildlink3.mk"
QT_CONFIG+=	dbus
.endif
