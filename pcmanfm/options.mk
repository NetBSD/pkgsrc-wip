# $NetBSD: options.mk,v 1.1.1.1 2012/05/20 04:06:16 jeremy-c-reed Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pcmanfm
PKG_SUPPORTED_OPTIONS=	hal
PKG_SUGGESTED_OPTIONS=	# none

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mhal)
.include "../../sysutils/hal/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-hal
.else
CONFIGURE_ARGS+=	--disable-hal
.endif
