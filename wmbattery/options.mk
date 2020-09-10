# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.wmbattery
PKG_SUPPORTED_OPTIONS=	hal upower

.include "../../mk/bsd.options.mk"

#
# hal support
#
.if !empty(PKG_OPTIONS:Mhal)
CONFIGURE_ARGS+=	--enable-hal
.include "../../sysutils/hal/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-hal
.endif

#
# upower support
#
.if !empty(PKG_OPTIONS:Mupower)
CONFIGURE_ARGS+=	--enable-upower
.include "../../sysutils/hal/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-upower
.endif
