# $NetBSD: options.mk,v 1.6 2007/01/28 09:37:52 thomasklausner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.bmpx
PKG_SUPPORTED_OPTIONS=	debug

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif
