# $NetBSD: options.mk,v 1.3 2011/05/27 13:23:09 rxg Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.chromium
.if ${MACHINE_ARCH} != "arm"
PKG_SUPPORTED_OPTIONS=	cups
.endif
PKG_SUPPORTED_OPTIONS+=	codecs debug gnome-keyring
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcups)
GYP_DEFINES+=	use_cups=1
.  include "../../print/cups/buildlink3.mk"
.else
GYP_DEFINES+=	use_cups=0
.endif

.if !empty(PKG_OPTIONS:Mcodecs)
FFMPEG_CODECS=	Chrome
FFMPEG_ARGS+=	--enable-decoder='theora,vorbis,libvpx,pcm_u8,pcm_s16le,pcm_f32le,aac,h264,mp3'
FFMPEG_ARGS+=	--enable-demuxer='ogg,matroska,wav,mp3,mov'
FFMPEG_ARGS+=	--enable-parser=mpegaudio
.else
FFMPEG_CODECS=	Chromium
FFMPEG_ARGS+=	--enable-decoder='theora,vorbis,libvpx,pcm_u8,pcm_s16le,pcm_f32le'
FFMPEG_ARGS+=	--enable-demuxer='ogg,matroska,wav'
.endif

.if !empty(PKG_OPTIONS:Mdebug)
BUILDTYPE=	Debug
.else
BUILDTYPE=	Release
.endif

.if !empty(PKG_OPTIONS:Mgnome-keyring)
GYP_DEFINES+=	linux_link_gnome_keyring=1
GYP_DEFINES+=	use_gnome_keyring=1
.  include "../../security/libgnome-keyring/buildlink3.mk"
.else
GYP_DEFINES+=	use_gnome_keyring=0
.endif
