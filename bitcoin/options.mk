# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.bitcoin
PKG_SUPPORTED_OPTIONS+=		miniupnpc dbus qrcode
PKG_SUGGESTED_OPTIONS+=		dbus qrcode

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mminiupnpc)
.include "../../wip/miniupnpc/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mdbus)
.include "../../x11/qt4-qdbus/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mqrcode)
.include "../../converters/qrencode/buildlink3.mk"
.endif
