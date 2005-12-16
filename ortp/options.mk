# $NetBSD: options.mk,v 1.1.1.1 2005/12/16 23:03:38 zul_ Exp $
#

PKG_OPTIONS_VAR=        PKG_OPTIONS.ortp
PKG_SUPPORTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=        --enable-ipv6
.endif
