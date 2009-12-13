# $NetBSD: options.mk,v 1.2 2009/12/13 23:12:56 pettai Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.softhsm
PKG_SUPPORTED_OPTIONS=		sigver
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

###
### Signature verification for debugging
###
.if !empty(PKG_OPTIONS:Msigver)
CONFIGURE_ARGS+=	--enable-sigver
.endif
