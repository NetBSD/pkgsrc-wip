# $NetBSD: options.mk,v 1.9 2012/11/16 20:46:42 kristerw Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.opendnssec
PKG_SUPPORTED_OPTIONS=		softhsm
PKG_SUGGESTED_OPTIONS=		softhsm

.include "../../mk/bsd.options.mk"

###
### SoftHSM
###
.if !empty(PKG_OPTIONS:Msofthsm)
DEPENDS+=	softhsm-[0-9]*:../../security/softhsm
.include "../../security/softhsm/buildlink3.mk"
.endif
