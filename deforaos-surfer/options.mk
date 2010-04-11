# $NetBSD: options.mk,v 1.1 2010/04/11 23:09:35 khorben Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.deforaos-surfer
PKG_SUPPORTED_OPTIONS=	embedded

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Membedded)
MAKE_FLAGS+=	CPPFLAGS=-DEMBEDDED
.endif
