# $NetBSD: options.mk,v 1.3 2014/01/15 17:34:23 nros Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qore
PKG_SUPPORTED_OPTIONS=	debug

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=        --enable-debug
.else
CONFIGURE_ARGS+=        --disable-debug
.endif
