# $NetBSD: options.mk,v 1.1 2012/04/18 23:38:23 khorben Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.deforaos-locker
PKG_SUPPORTED_OPTIONS=	embedded

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Membedded)
MAKE_FLAGS+=	CPPFLAGS=-DEMBEDDED
.endif
