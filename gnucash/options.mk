# $NetBSD: options.mk,v 1.3 2006/02/11 21:26:42 fgudin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnucash
PKG_SUPPORTED_OPTIONS=	libofx

.include "../../mk/bsd.options.mk"

###
### Whether to build with the OFX importation module.
###

.if !empty(PKG_OPTIONS:Mlibofx)
.  include "../../finance/libofx/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-ofx
.endif
