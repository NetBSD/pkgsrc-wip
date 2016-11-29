# $NetBSD$

# TODO: make qt optional, and support qt5
# TODO: create split package for qt gui

PKG_OPTIONS_VAR=		PKG_OPTIONS.bitcoin
PKG_SUPPORTED_OPTIONS+=		miniupnpc dbus qrcode
PKG_SUGGESTED_OPTIONS+=		dbus qrcode

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mminiupnpc)
.include "../../wip/miniupnpc/buildlink3.mk"
.endif

# TODO: Add a comment explaining what this does, and decide if it
# should just be enabled instead of being an option.
.if !empty(PKG_OPTIONS:Mdbus)
.include "../../x11/qt4-qdbus/buildlink3.mk"
.endif

# TODO: If this is small, and only useful with qt, just depend
# on it when qt is enabled.
.if !empty(PKG_OPTIONS:Mqrcode)
.include "../../converters/qrencode/buildlink3.mk"
.endif
