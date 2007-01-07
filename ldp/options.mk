# $NetBSD: options.mk,v 1.1 2007/01/07 11:18:24 koifren Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ldp
PKG_SUPPORTED_OPTIONS=	ayame

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mayame)
CFLAGS+=-DAYAME_STACK
.endif
