# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.yoshimidi
PKG_SUPPORTED_OPTIONS=		alsa jack
PKG_SUGGESTED_OPTIONS.Linux=	alsa
PKG_SUGGESTED_OPTIONS.NetBSD=	jack

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mjack)
.  include "../../audio/jack/buildlink3.mk"
.endif
