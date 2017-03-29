# $NetBSD: options.mk,v 1.35 2015/12/10 19:33:41 shattered Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.freeswitch
PKG_SUPPORTED_OPTIONS=  zrtp	

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Zrtp)
CONFIGURE_ARGS+=	--enable-system-xmlrpc-c --enable-zrtp	
.endif
