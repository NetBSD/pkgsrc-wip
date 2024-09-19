# $NetBSD: options.mk,v 1.1 2012/11/09 18:41:10 jihbed Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.freefem++
PKG_SUPPORTED_OPTIONS=	amd umfpack
#PKG_SUGGESTED_OPTIONS=	pulseaudio

.include "../../mk/bsd.options.mk"

#.if !empty(PKG_OPTIONS:Mpulseaudio)
#.include "../../audio/pulseaudio/buildlink3.mk"
#.else
#CMAKE_CONFIGURE_ARGS+=	-DNO_PULSE_SIMPLE:BOOL=TRUE
#.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DNO_PULSE_SIMPLE:BOOL=TRUE
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DNO_PULSE_SIMPLE:BOOL=TRUE
.endif
