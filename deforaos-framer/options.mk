# $NetBSD: options.mk,v 1.1 2010/04/11 23:12:05 khorben Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.deforaos-framer
PKG_SUPPORTED_OPTIONS=	embedded

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Membedded)
MAKE_FLAGS+=	CPPFLAGS=-DEMBEDDED
.endif
