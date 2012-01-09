# $NetBSD: options.mk,v 1.1.1.1 2012/01/09 15:46:04 khorben Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.deforaos-surfer
PKG_SUPPORTED_OPTIONS=	embedded

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Membedded)
MAKE_FLAGS+=	CPPFLAGS=-DEMBEDDED
.endif
