# $NetBSD: options.mk,v 1.2 2006/10/29 08:32:49 shattered Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.ortp
PKG_SUPPORTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif
