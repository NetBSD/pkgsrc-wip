# $NetBSD: options.mk,v 1.1.1.1 2006/06/17 09:19:02 gschwarz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pdnsd
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif
