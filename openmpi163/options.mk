# $NetBSD: options.mk,v 1.1 2013/06/21 16:40:32 outpaddling Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.openmpi
PKG_SUPPORTED_OPTIONS=	debug

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif
