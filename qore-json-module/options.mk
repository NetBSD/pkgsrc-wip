# $NetBSD: options.mk,v 1.1 2014/02/16 13:43:27 nros Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.qore-json-module
PKG_SUPPORTED_OPTIONS=	debug
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=        --enable-debug
.else
CONFIGURE_ARGS+=        --disable-debug
.endif
