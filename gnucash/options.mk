# $NetBSD: options.mk,v 1.2 2006/02/11 20:39:03 fgudin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnucash
PKG_SUPPORTED_OPTIONS=	libofx

.include "../../mk/bsd.options.mk"

###
### Whether to build with the OFX importation module.
###

.if !empty(PKG_OPTIONS:Mofx)
.  include "../../finance/libofx/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-ofx
.endif
