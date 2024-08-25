# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.rtaudio
PKG_OPTIONS_SET.driver=		alsa coreaudio jack oss pulseaudio
PKG_OPTIONS_NONEMPTY_SETS=	driver

.include "../../mk/bsd.prefs.mk"

PKG_SUGGESTED_OPTIONS=	jack pulseaudio

.if ${OPSYS} == "Linux"
PKG_SUGGESTED_OPTIONS+=	alsa
.endif

.if ${OPSYS} == "Darwin"
PKG_SUGGESTED_OPTIONS+=	coreaudio
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CMAKE_CONFIGURE_ARGS+=	-DRTAUDIO_API_ALSA=ON
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DRTAUDIO_API_ALSA=OFF
.endif

.if !empty(PKG_OPTIONS:Mcoreaudio)
CMAKE_CONFIGURE_ARGS+=	-DRTAUDIO_API_CORE=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DRTAUDIO_API_CORE=OFF
.endif

.if !empty(PKG_OPTIONS:Mjack)
CMAKE_CONFIGURE_ARGS+=	-DRTAUDIO_API_JACK=ON
.include "../../audio/jack/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DRTAUDIO_API_JACK=OFF
.endif

.if !empty(PKG_OPTIONS:Moss)
CMAKE_CONFIGURE_ARGS+=	-DRTAUDIO_API_OSS=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DRTAUDIO_API_OSS=OFF
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CMAKE_CONFIGURE_ARGS+=	-DRTAUDIO_API_PULSE=ON
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DRTAUDIO_API_PULSE=OFF
.endif
