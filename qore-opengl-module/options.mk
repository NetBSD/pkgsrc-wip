# $NetBSD: options.mk,v 1.2 2014/02/16 15:56:54 nros Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.qore-opengl-module
PKG_SUPPORTED_OPTIONS=	debug
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=        --enable-debug
.else
CONFIGURE_ARGS+=        --disable-debug
.endif
