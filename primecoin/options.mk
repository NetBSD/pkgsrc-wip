# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.primecoin
PKG_SUPPORTED_OPTIONS+=		miniupnpc dbus qrcode
PKG_SUGGESTED_OPTIONS+=		qrcode

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mminiupnpc)
QMAKE_OPTIONS+=	USE_UPNP=1
.include "../../wip/miniupnpc/buildlink3.mk"
.else
QMAKE_OPTIONS+=	USE_UPNP=-
.endif

.if !empty(PKG_OPTIONS:Mdbus)
QMAKE_OPTIONS+=	USE_DBUS=1
.include "../../x11/qt4-qdbus/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mqrcode)
QMAKE_OPTIONS+=	USE_QRCODE=1
.include "../../converters/qrencode/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Minet6)
QMAKE_OPTIONS+=	USE_IPV6=0
.endif
