# $NetBSD: options.mk,v 1.1 2011/02/12 15:10:22 khorben Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.deforaos-editor
PKG_SUPPORTED_OPTIONS=	embedded

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Membedded)
MAKE_FLAGS+=	CPPFLAGS=-DEMBEDDED
.endif
