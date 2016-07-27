# $NetBSD: options.mk,v 1.1 2013/12/25 01:14:35 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pyglet
PKG_SUPPORTED_OPTIONS=	alsa openal
PKG_SUGGESTED_OPTIONS+=	openal

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mopenal)
.include "../../audio/openal-soft/buildlink3.mk"
.endif
