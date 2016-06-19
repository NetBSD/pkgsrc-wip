# $NetBSD: options.mk,v 1.1 2016/06/12 20:31:10 kamil Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ardour

PKG_SUPPORTED_OPTIONS=	alsa jack dummy
PKG_SUGGESTED_OPTIONS=	alsa jack

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
WAF_ARGS+=      --with-backends=alsa
.endif

.if !empty(PKG_OPTIONS:Mjack)
.include "../../audio/jack/buildlink3.mk"
WAF_ARGS+=      --with-backends=jack
.endif

# Useful for developers
.if !empty(PKG_OPTIONS:Mjack)
WAF_ARGS+=      --with-backends=dummy
.endif

WAF_ARGS+=      --with-backends=alsa,jack,dummy
