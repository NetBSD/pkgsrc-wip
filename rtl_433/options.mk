# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.rtl_433
PKG_SUPPORTED_OPTIONS=		rtl-sdr soapy-sdr
PKG_SUGGESTED_OPTIONS=		rtl-sdr soapy-sdr

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mrtl-sdr)
.include "../../ham/rtl-sdr/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msoapy-sdr)
.include "../../ham/soapy-sdr/buildlink3.mk"
.endif
