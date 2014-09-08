# $NetBSD: options.mk,v 1.2 2014/09/08 20:37:40 thomasklausner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ppr
PKG_SUPPORTED_OPTIONS=	netpbm
PKG_DEFAULT_OPTIONS=	netpbm
.include "../../mk/bsd.options.mk"

###
### Create filters using netpbm?
###
.if !empty(PKG_OPTIONS:Mnetpbm)
DEPENDS+=	netpbm-[0-9]*:../../graphics/netpbm
.endif
