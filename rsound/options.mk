# $NetBSD: options.mk,v 1.3 2015/03/15 21:03:23 thomasklausner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rsound
PKG_SUPPORTED_OPTIONS=	alsa jack libao openal oss portaudio pulseaudio
PKG_SUPPORTED_OPTIONS+=	samplerate syslog
PKG_SUGGESTED_OPTIONS=	libao openal oss pulseaudio samplerate

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-alsa
.else
CONFIGURE_ARGS+=	--disable-alsa
.endif

.if !empty(PKG_OPTIONS:Mjack)
.include "../../audio/jack/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-jack
#BUILDLINK_ABI_DEPENDS.jack+=	jack>=0.120.1
.else
CONFIGURE_ARGS+=	--disable-jack
.endif

.if !empty(PKG_OPTIONS:Mlibao)
.include "../../audio/libao/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-libao
.else
CONFIGURE_ARGS+=	--disable-libao
.endif

.if !empty(PKG_OPTIONS:Msamplerate)
.include "../../audio/libsamplerate/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-samplerate
.else
CONFIGURE_ARGS+=	--disable-samplerate
.endif

.if !empty(PKG_OPTIONS:Mopenal)
.include "../../audio/openal-soft/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-al
.else
CONFIGURE_ARGS+=	--disable-al
.endif

.if !empty(PKG_OPTIONS:Moss)
.include "../../mk/oss.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-oss
.else
CONFIGURE_ARGS+=	--disable-oss
.endif

.if !empty(PKG_OPTIONS:Mportaudio)
.include "../../audio/portaudio/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-portaudio
.else
CONFIGURE_ARGS+=	--disable-portaudio
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pulse
.else
CONFIGURE_ARGS+=	--disable-pulse
.endif

.if !empty(PKG_OPTIONS:Msyslog)
CONFIGURE_ARGS+=	--enable-syslog
.else
CONFIGURE_ARGS+=	--disable-syslog
.endif
