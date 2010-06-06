# $NetBSD: options.mk,v 1.1 2010/06/06 15:23:33 khorben Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.deforaos-todo
PKG_SUPPORTED_OPTIONS=	embedded

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Membedded)
MAKE_FLAGS+=	CPPFLAGS=-DEMBEDDED
.endif
