# $NetBSD: options.mk,v 1.3 2019/09/16 22:46:20 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.xwax
PKG_SUPPORTED_OPTIONS=		alsa jack
PKG_SUGGESTED_OPTIONS=
PKG_SUGGESTED_OPTIONS.Linux=	alsa

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
MAKE_FLAGS+=	ALSA=1
.include "../../audio/alsa-lib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mjack)
MAKE_FLAGS+=	JACK=1
.include "../../audio/jack/buildlink3.mk"
.endif
