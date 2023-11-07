# $NetBSD: options.mk,v 1.2 2019/08/07 23:49:02 fox Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.din
PKG_OPTIONS_OPTIONAL_GROUPS=	backend
PKG_OPTIONS_GROUP.backend=	alsa jack coreaudio
PKG_SUGGESTED_OPTIONS=		jack

.include "../../mk/bsd.options.mk"

###
### Support ALSA
###
.if !empty(PKG_OPTIONS:Malsa)
CXXFLAGS+=	-D__LINUX_ALSA__
LIBS+=		-lasound
.include "../../audio/alsa-lib/buildlink3.mk"
.endif

###
### Support JACK
###
.if !empty(PKG_OPTIONS:Mjack)
CXXFLAGS+=	-D__UNIX_JACK__
LIBS+=		-ljack
.include "../../audio/jack/buildlink3.mk"
.endif

###
### Support CoreAudio
###
.if !empty(PKG_OPTIONS:Mcoreaudio)
CXXFLAGS+=	-D__MACOSX_CORE__
LIBS+=		-framework OpenGL -framework CoreMIDI -framework CoreAudio -framework CoreFoundation
.endif
