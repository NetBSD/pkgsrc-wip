# $NetBSD: options.mk,v 1.1 2015/01/01 08:27:02 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mate-applets
PKG_SUPPORTED_OPTIONS=	hal inet6
PKG_SUGGESTED_OPTIONS+=	hal inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mhal)
.include "../../sysutils/hal/buildlink3.mk"
CONFIGURE_ARGS+=	--with-hal
.else
CONFIGURE_ARGS+=	--without-hal
.endif
