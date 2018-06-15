# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.din
PKG_SUPPORTED_OPTIONS=	jack alsa
PKG_SUGGESTED_OPTIONS=	jack

.include "../../mk/bsd.options.mk"

###
### Support JACK
###
.if !empty(PKG_OPTIONS:Mjack)
CXXFLAGS+=		-D__UNIX_JACK__
.endif

###
### Support ALSA
###
.if !empty(PKG_OPTIONS:Malsa)
CXXFLAGS+=		-D__LINUX_ALSA__
.endif
