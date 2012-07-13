# $NetBSD: options.mk,v 1.1 2012/07/13 13:50:31 khorben Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.deforaos-mixer
PKG_SUPPORTED_OPTIONS=	embedded

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Membedded)
MAKE_FLAGS+=	CPPFLAGS=-DEMBEDDED
.endif
