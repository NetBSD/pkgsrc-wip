# $NetBSD: options.mk,v 1.2 2012/12/24 03:44:13 khorben Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.deforaos-panel
PKG_SUPPORTED_OPTIONS=	embedded

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Membedded)
MAKE_FLAGS+=	CPPFLAGS=-DEMBEDDED
.endif
