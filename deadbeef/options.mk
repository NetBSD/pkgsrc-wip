# $NetBSD: options.mk,v 1.2 2019/06/17 08:08:31 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.deadbeef

# Audio outputs
PKG_SUPPORTED_OPTIONS+=		alsa pulseaudio
# Additional codecs
PKG_SUPPORTED_OPTIONS+=		ffmpeg musepack wavpack

PKG_SUGGESTED_OPTIONS+=		ffmpeg musepack wavpack
PKG_SUGGESTED_OPTIONS.Linux+=	alsa

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		alsa
.if !empty(PKG_OPTIONS:Malsa)
PLIST.alsa=		yes
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-alsa
.endif

PLIST_VARS+=		pulse
.if !empty(PKG_OPTIONS:Mpulseaudio)
PLIST.pulse=		yes
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pulse
.endif

PLIST_VARS+=		ffmpeg
.if !empty(PKG_OPTIONS:Mffmpeg)
PLIST.ffmpeg=		yes
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ffmpeg
.endif

PLIST_VARS+=		musepack
.if !empty(PKG_OPTIONS:Mmusepack)
PLIST.musepack=		yes
.include "../../audio/musepack/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-musepack
.endif

PLIST_VARS+=		wavpack
.if !empty(PKG_OPTIONS:Mwavpack)
PLIST.wavpack=		yes
.include "../../audio/wavpack/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-wavpack
.endif
