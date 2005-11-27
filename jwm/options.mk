# $NetBSD: options.mk,v 1.1 2005/11/27 10:08:44 leonardschmidt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.jwm
PKG_SUPPORTED_OPTIONS=	debug

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif
