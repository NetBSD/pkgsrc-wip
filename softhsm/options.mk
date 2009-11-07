# $NetBSD: options.mk,v 1.1 2009/11/07 22:45:18 pettai Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.softhsm
PKG_SUPPORTED_OPTIONS=		64bit
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

###
### 64-bit
###
.if !empty(PKG_OPTIONS:M64bit)
CONFIGURE_ARGS+=	--enable-64bit

.endif
