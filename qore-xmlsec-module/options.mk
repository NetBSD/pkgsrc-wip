# $NetBSD: options.mk,v 1.2 2014/02/16 19:55:15 nros Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.qore-xmlsec-module
PKG_SUPPORTED_OPTIONS=	debug
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=        --enable-debug
.else
CONFIGURE_ARGS+=        --disable-debug
.endif
