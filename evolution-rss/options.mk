# $NetBSD: options.mk,v 1.1.1.1 2010/05/03 14:57:49 jihbed Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.evolution-rss
PKG_SUPPORTED_OPTIONS=	webkit dbus gecko
PKG_SUGGESTED_OPTIONS=	dbus

.include "../../mk/bsd.options.mk"


.if !empty(PKG_OPTIONS:Mdbus)
.   include "../../sysutils/dbus/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif

.if !empty(PKG_OPTIONS:Mgecko)
.   include "../../devel/xulrunner/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gecko
.endif

.if !empty(PKG_OPTIONS:Mwebkit )
.   include "../../www/webkit-gtk/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-webkit
.endif
