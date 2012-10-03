# $NetBSD: options.mk,v 1.1 2012/10/03 23:23:23 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.retroarch
PKG_SUPPORTED_OPTIONS=	alsa cg ffmpeg freetype jack libxml2 openal opengl oss
PKG_SUPPORTED_OPTIONS+=	png pulseaudio python rsound samplerate sdl threads
PKG_SUPPORTED_OPTIONS+=	xvideo
PKG_SUGGESTED_OPTIONS=	ffmpeg freetype libxml2 openal opengl png pulseaudio
PKG_SUGGESTED_OPTIONS+=	rsound samplerate sdl threads xvideo


.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
CONFIGURE_ARGS+=		--enable-alsa
.else
CONFIGURE_ARGS+=		--disable-alsa
.endif

.if !empty(PKG_OPTIONS:Mcg)
.include "../../wip/Cg-compiler/buildlink3.mk"
CONFIGURE_ARGS+=		--enable-cg
# Need to work out where to tell configure to find Cg's libs
.else
CONFIGURE_ARGS+=		--disable-cg
.endif

.if !empty(PKG_OPTIONS:Mffmpeg)
.include "../../multimedia/ffmpeg/buildlink3.mk"
CONFIGURE_ARGS+=		--enable-ffmpeg
.else
CONFIGURE_ARGS+=		--disable-ffmpeg
.endif

.if !empty(PKG_OPTIONS:Mfreetype)
.include "../../graphics/freetype2/buildlink3.mk"
CONFIGURE_ARGS+=		--enable-freetype
.else
CONFIGURE_ARGS+=		--disable-freetype
.endif

.if !empty(PKG_OPTIONS:Mjack)
.include "../../audio/jack/buildlink3.mk"
CONFIGURE_ARGS+=		--enable-jack
BUILDLINK_ABI_DEPENDS.jack+=	jack>=0.120.1
.else
CONFIGURE_ARGS+=		--disable-jack
.endif

.if !empty(PKG_OPTIONS:Msamplerate)
.include "../../audio/libsamplerate/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibxml2)
.include "../../textproc/libxml2/buildlink3.mk"
CONFIGURE_ARGS+=		--enable-xml
.else
CONFIGURE_ARGS+=		--disable-xml
.endif

.if !empty(PKG_OPTIONS:Mopenal)
.include "../../audio/openal/buildlink3.mk"
CONFIGURE_ARGS+=		--enable-al
.else
CONFIGURE_ARGS+=		--disable-al
.endif

.if !empty(PKG_OPTIONS:Mopengl)
.include "../../graphics/MesaLib/buildlink3.mk"
CONFIGURE_ARGS+=		--enable-opengl
# Checking function glFramebufferTexture2D in -lGL ... no <- Fix me.
.else
CONFIGURE_ARGS+=		--disable-opengl
.endif

.if !empty(PKG_OPTIONS:Moss)
.include "../../mk/oss.buildlink3.mk"
CONFIGURE_ARGS+=		--enable-oss
.else
CONFIGURE_ARGS+=		--disable-oss
.endif

.if !empty(PKG_OPTIONS:Mpng)
.include "../../graphics/png/buildlink3.mk"
CONFIGURE_ARGS+=		--enable-libpng
BUILDLINK_ABI_DEPENDS.png+=	png>=1.5
.else
CONFIGURE_ARGS+=		--disable-libpng
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
CONFIGURE_ARGS+=		--enable-pulse
.else
CONFIGURE_ARGS+=		--disable-pulse
.endif

.if !empty(PKG_OPTIONS:Mpython)
.include "../../lang/python/pyversion.mk"
CONFIGURE_ARGS+=		--enable-python
PYTHON_VERSIONS_ACCEPTED=	32 31
.else
CONFIGURE_ARGS+=		--disable-python
.endif

.if !empty(PKG_OPTIONS:Mrsound)
.include "../../wip/rsound/buildlink3.mk"
CONFIGURE_ARGS+=		--enable-rsound
BUILDLINK_ABI_DEPENDS.rsound+=	rsound>=1.1
.else
CONFIGURE_ARGS+=		--disable-rsound
.endif

.if !empty(PKG_OPTIONS:Msdl)
.include "../../graphics/SDL_image/buildlink3.mk"
CONFIGURE_ARGS+=		--enable-sdl_image
.else
CONFIGURE_ARGS+=		--disable-sdl_image
.endif

.if !empty(PKG_OPTIONS:Mthreads)
.include "../../mk/pthread.buildlink3.mk"
CONFIGURE_ARGS+=		--enable-threads
.else
CONFIGURE_ARGS+=		--disable-threads
.endif

.if !empty(PKG_OPTIONS:Mxvideo)
.include "../../x11/libXvMC/buildlink3.mk"
CONFIGURE_ARGS+=		--enable-xvideo
.else
CONFIGURE_ARGS+=		--disable-xvideo
.endif
