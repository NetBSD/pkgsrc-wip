# $NetBSD: options.mk,v 1.1 2011/06/06 00:52:22 khorben Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.deforaos-mailer
PKG_SUPPORTED_OPTIONS=	embedded

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Membedded)
MAKE_FLAGS+=	CPPFLAGS=-DEMBEDDED
.endif
