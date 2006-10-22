# $NetBSD: options.mk,v 1.1 2006/10/22 19:21:32 anthony_mallet Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.omniORB
PKG_SUPPORTED_OPTIONS=	ipv6
PKG_SUGGESTED_OPTIONS=	ipv6

.include "../../mk/bsd.options.mk"

.if empty(PKG_OPTIONS:Mipv6)
CONFIGURE_ARGS+=--without-ipv6
.endif
