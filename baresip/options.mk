# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.baresip
PKG_SUPPORTED_OPTIONS=		alsa cairo ffmpeg gstreamer gtk x265 ilbc jack
PKG_SUPPORTED_OPTIONS+=		libvpx oss opencore-amr opus portaudio
PKG_SUPPORTED_OPTIONS+=		pulseaudio sdl sdl2 sndfile sndio speex v4l2
PKG_SUPPORTED_OPTIONS+=		x11
PKG_SUGGESTED_OPTIONS=		oss ilbc speex

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

PLIST_VARS+=			${PKG_SUPPORTED_OPTIONS}

###
### ALSA support (audio output)
###
.if !empty(PKG_OPTIONS:Malsa)
PLIST.alsa=	yes
MAKE_FLAGS+=	USE_ALSA=yes
.include "../../audio/alsa-lib/buildlink3.mk"
.else
MAKE_FLAGS+=	USE_ALSA=
.endif

###
### cairo support (video input)
###
.if !empty(PKG_OPTIONS:Mcairo)
PLIST.cairo=	yes
MAKE_FLAGS+=	USE_CAIRO=yes
.include "../../graphics/cairo/buildlink3.mk"
.else
MAKE_FLAGS+=	USE_CAIRO=
.endif

###
### Gstreamer1 support (video codecs)
###
.if !empty(PKG_OPTIONS:Mgstreamer)
PLIST.gstreamer=	yes
MAKE_FLAGS+=	USE_GST1=yes
MAKE_FLAGS+=	USE_GST_VIDEO1=yes
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.else
MAKE_FLAGS+=	USE_GST1=
MAKE_FLAGS+=	USE_GST_VIDEO1=
.endif

###
### GTK gui support
###
.if !empty(PKG_OPTIONS:Mgtk)
PLIST.gtk=	yes
MAKE_FLAGS+=	USE_GTK=yes
.include "../../x11/gtk2/buildlink3.mk"
.else
MAKE_FLAGS+=	USE_GTK=
.endif

###
### H265 support (video codec)
###
.if !empty(PKG_OPTIONS:Mx265)
PLIST.x265=	yes
MAKE_FLAGS+=	USE_H265=yes
LFLAGS+=	${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.ffmpeg3}/${BUILDLINK_LIBDIRS.ffmpeg3}
LFLAGS+=	-L${BUILDLINK_PREFIX.ffmpeg3}/${BUILDLINK_LIBDIRS.ffmpeg3}
.include "../../multimedia/ffmpeg3/buildlink3.mk"
.include "../../multimedia/x265/buildlink3.mk"
.else
MAKE_FLAGS+=	USE_H265=
.endif

###
### ffmpeg support (video input)
###
.if !empty(PKG_OPTIONS:Mffmpeg)
PLIST.ffmpeg=	yes
MAKE_FLAGS+=	USE_AVCODEC=yes
MAKE_FLAGS+=	USE_AVFORMAT=yes
LFLAGS+=	${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.ffmpeg3}/${BUILDLINK_LIBDIRS.ffmpeg3}
LFLAGS+=	-L${BUILDLINK_PREFIX.ffmpeg3}/${BUILDLINK_LIBDIRS.ffmpeg3}
.include "../../multimedia/ffmpeg3/buildlink3.mk"
.include "../../multimedia/x264-devel/buildlink3.mk"
.else
MAKE_FLAGS+=	USE_AVCODEC=
MAKE_FLAGS+=	USE_AVFORMAT=
.endif

###
### ILBC support (audio codec)
###
.if !empty(PKG_OPTIONS:Milbc)
PLIST.ilbc=	yes
MAKE_FLAGS+=	USE_ILBC=yes
#.include "../../wip/ilbc-rfc3951/buildlink3.mk"
.include "../../wip/libilbc/buildlink3.mk"
.else
MAKE_FLAGS+=	USE_ILBC=
.endif

###
### Jack Audio Connection Kit support (audio output)
###
.if !empty(PKG_OPTIONS:Mjack)
PLIST.jack=	yes
MAKE_FLAGS+=	USE_JACK=yes
.include "../../audio/jack/buildlink3.mk"
.else
MAKE_FLAGS+=	USE_JACK=
.endif

###
### vp8 and vp9 support (video codec)
###
.if !empty(PKG_OPTIONS:Mlibvpx)
PLIST.libvpx=	yes
MAKE_FLAGS+=	USE_VPX=yes
.include "../../multimedia/libvpx/buildlink3.mk"
.else
MAKE_FLAGS+=	USE_VPX=
.endif

###
### OSS support (audio output)
###
.if !empty(PKG_OPTIONS:Moss)
PLIST.oss=	yes
MAKE_FLAGS+=	USE_OSS=yes    # full-duplex issues
.else
MAKE_FLAGS+=	USE_OSS=
.endif

###
### opencore-amr support (audio codec)
###
.if !empty(PKG_OPTIONS:Mopencore-amr)
PLIST.opencore-amr=	yes
MAKE_FLAGS+=	USE_AMR=yes
.include "../../audio/opencore-amr/buildlink3.mk"
.else
MAKE_FLAGS+=	USE_AMR=
.endif

###
### opus support (audio codec)
###
.if !empty(PKG_OPTIONS:Mopus)
PLIST.opus=	yes
MAKE_FLAGS+=	USE_OPUS=yes
.include "../../audio/libopus/buildlink3.mk"
.else
MAKE_FLAGS+=	USE_OPUS=
.endif

###
### Portaudio support (audio output)
###
.if !empty(PKG_OPTIONS:Mportaudio)
PLIST.portaudio=	yes
MAKE_FLAGS+=	USE_PORTAUDIO=yes
.include "../../audio/portaudio/buildlink3.mk"
.else
MAKE_FLAGS+=	USE_PORTAUDIO=
.endif

###
### Pulseaudio support (audio output)
###
.if !empty(PKG_OPTIONS:Mpulseaudio)
PLIST.pulseaudio=	yes
MAKE_FLAGS+=	USE_PULSE=yes
.include "../../audio/pulseaudio/buildlink3.mk"
.else
MAKE_FLAGS+=	USE_PULSE=
.endif

###
### SDL support (video output)
###
.if !empty(PKG_OPTIONS:Msdl)
PLIST.sdl=	yes
MAKE_FLAGS+=	USE_SDL=yes
.include "../../devel/SDL/buildlink3.mk"
.else
MAKE_FLAGS+=	USE_SDL=
.endif

###
### SDL2 support (video output)
###
.if !empty(PKG_OPTIONS:Msdl2)
PLIST.sdl2=	yes
MAKE_FLAGS+=	USE_SDL2=yes
.include "../../devel/SDL2/buildlink3.mk"
.else
MAKE_FLAGS+=	USE_SDL2=
.endif

###
### sndfile support (audio input)
###
.if !empty(PKG_OPTIONS:Msndfile)
PLIST.sndfile=	yes
MAKE_FLAGS+=	USE_SNDFILE=yes
.include "../../audio/libsndfile/buildlink3.mk"
.else
MAKE_FLAGS+=	USE_SNDFILE=
.endif

###
### sndio support (audio output)
###
.if !empty(PKG_OPTIONS:Msndio)
PLIST.sndio=	yes
MAKE_FLAGS+=	USE_SNDIO=yes
# XXX this needs a buildlink3.mk ?
DEPENDS+=	sndio-[0-9]*:../../wip/sndio
.else
MAKE_FLAGS+=	USE_SNDIO=
.endif

###
### speex support (audio codec)
###
.if !empty(PKG_OPTIONS:Mspeex)
PLIST.speex=	yes
MAKE_FLAGS+=	HAVE_SPEEXDSP=yes
MAKE_FLAGS+=	USE_SPEEX_AEC=yes
MAKE_FLAGS+=	USE_SPEEX_PP=yes
.include "../../audio/speexdsp/buildlink3.mk"
.else
MAKE_FLAGS+=	HAVE_SPEEXDSP=
MAKE_FLAGS+=	USE_SPEEX_AEC=
MAKE_FLAGS+=	USE_SPEEX_PP=
.endif

###
### Video4Linux2 support (video input)
###
.if !empty(PKG_OPTIONS:Mv4l2)
PLIST.v4l2=	yes
MAKE_FLAGS+=	HAVE_LIBV4L2=yes
MAKE_FLAGS+=	USE_V4L2=yes
.include "../../graphics/libv4l/buildlink3.mk"
.else
MAKE_FLAGS+=	USE_V4L2=
.endif

###
### x11 support (video output)
###
.if !empty(PKG_OPTIONS:Mx11)
PLIST.x11=	yes
LFLAGS+=	${X11_LDFLAGS}
MAKE_FLAGS+=	USE_X11=yes
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.else
MAKE_FLAGS+=	USE_X11=
.endif
