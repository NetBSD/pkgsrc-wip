# $NetBSD: options.mk,v 1.3 2015/04/09 03:01:44 krytarowski Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mate-utils
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6=yes
.else
CONFIGURE_ARGS+=	--enable-ipv6=no
.endif
