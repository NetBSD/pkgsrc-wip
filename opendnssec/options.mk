# $NetBSD: options.mk,v 1.8 2010/11/17 11:12:00 pettai Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.opendnssec
PKG_SUPPORTED_OPTIONS=		softhsm
PKG_SUGGESTED_OPTIONS=		softhsm

.include "../../mk/bsd.options.mk"

###
### SoftHSM
###
.if !empty(PKG_OPTIONS:Msofthsm)
DEPENDS+=	softhsm:../../security/softhsm
.include "../../security/softhsm/buildlink3.mk"
.endif
