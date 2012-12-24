# $NetBSD: options.mk,v 1.2 2012/12/24 03:33:27 khorben Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.deforaos-browser
PKG_SUPPORTED_OPTIONS=	embedded

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Membedded)
MAKE_FLAGS+=	CPPFLAGS=-DEMBEDDED
.endif
