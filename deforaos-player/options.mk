# $NetBSD: options.mk,v 1.1 2011/03/17 11:51:38 khorben Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.deforaos-player
PKG_SUPPORTED_OPTIONS=	embedded

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Membedded)
MAKE_FLAGS+=	CPPFLAGS=-DEMBEDDED
.endif
