# $NetBSD: options.mk,v 1.3 2014/08/11 23:10:14 thomasklausner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pjproject
PKG_SUPPORTED_OPTIONS=	alsa ffmpeg gsm ilbc openssl samplerate sdl2 speex v4l2
PKG_SUPPORTED_OPTIONS+=	x264
PKG_SUGGESTED_OPTIONS+=	ffmpeg gsm ilbc openssl samplerate sdl2 speex x264

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mffmpeg)
.include "../../multimedia/ffmpeg1/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ffmpeg
.endif

.if !empty(PKG_OPTIONS:Mgsm)
.include "../../audio/gsm/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gsm-codec
.endif

.if !empty(PKG_OPTIONS:Milbc)
.include "../../wip/ilbc-rfc3951/buildlink3.mk"
.else
CONFIGURE_ARGS+=        --disable-ilbc-codec
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

.if !empty(PKG_OPTIONS:Msamplerate)
.include "../../audio/libsamplerate/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msdl2)
.include "../../devel/SDL2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-sdl
.endif

.if !empty(PKG_OPTIONS:Mspeex)
.include "../../audio/speex/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-speex-aec --disable-speex-codec
.endif

.if !empty(PKG_OPTIONS:Mv4l2)
# XXX needs linux/videodev2.h
.include "../../graphics/libv4l/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-v4l2
.endif

.if !empty(PKG_OPTIONS:Mx264)
.include "../../multimedia/x264-devel/buildlink3.mk"
.endif
