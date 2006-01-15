# $NetBSD: options.mk,v 1.1 2006/01/15 17:34:34 hfath Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tiff
PKG_SUPPORTED_OPTIONS=	netpbm
PKG_DEFAULT_OPTIONS=	netpbm
.include "../../mk/bsd.options.mk"

###
### Create filters using netpbm?
###
.if !empty(PKG_OPTIONS:Mnetpbm)
.include "../../graphics/netpbm/buildlink3.mk"
.endif
