# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.din
PKG_SUPPORTED_OPTIONS=	alsa jack
PKG_SUGGESTED_OPTIONS=	jack

.include "../../mk/bsd.options.mk"

###
### Support ALSA
###
.if !empty(PKG_OPTIONS:Malsa)
CXXFLAGS+=		-D__LINUX_ALSA__
.include "../../audio/alsa-lib/buildlink3.mk"
.endif

###
### Support JACK
###
.if !empty(PKG_OPTIONS:Mjack)
CXXFLAGS+=		-D__UNIX_JACK__
.include "../../audio/jack/buildlink3.mk"
.endif
