# $NetBSD: options.mk,v 1.1 2010/11/07 15:55:03 khorben Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.deforaos-phone
PKG_SUPPORTED_OPTIONS=	embedded

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Membedded)
MAKE_FLAGS+=	CPPFLAGS=-DEMBEDDED
.endif
