# $NetBSD: options.mk,v 1.1 2014/01/14 19:27:10 nros Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qore
PKG_SUPPORTED_OPTIONS=	debug doc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=        --enable-debug
.else
CONFIGURE_ARGS+=        --disable-debug
.endif

.if !empty(PKG_OPTIONS:Mdoc)
.else
CONFIGURE_ARGS+=        --with-doxygen=no
.endif
