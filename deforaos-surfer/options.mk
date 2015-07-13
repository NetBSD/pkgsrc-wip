# $NetBSD: options.mk,v 1.3 2015/07/13 15:03:22 thomasklausner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.deforaos-surfer
PKG_SUPPORTED_OPTIONS=	embedded

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Membedded)
MAKE_FLAGS+=	CPPFLAGS=-DEMBEDDED
.endif
