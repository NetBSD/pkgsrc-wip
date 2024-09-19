# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.timg
PKG_SUPPORTED_OPTIONS+=	ffmpeg graphicsmagick jpegturbo

PKG_SUGGESTED_OPTIONS=	ffmpeg graphicsmagick

.include "../../mk/bsd.options.mk"

###
### Use ffmpeg
###
.if !empty(PKG_OPTIONS:Mffmpeg)
CMAKE_CONFIGURE_ARGS+= 	-DWITH_VIDEO_DECODING=ON
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+= 	-DWITH_VIDEO_DECODING=OFF
.endif

###
### Use GraphicsMagick
###
.if !empty(PKG_OPTIONS:Mgraphicsmagick)
CMAKE_CONFIGURE_ARGS+= 	-DWITH_GRAPHICSMAGICK=ON
.include "../../graphics/GraphicsMagick/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+= 	-DWITH_GRAPHICSMAGICK=OFF
.endif

###
### Use OpenSlide - Not yet in pkgsrc, so disabled
###
#.if !empty(PKG_OPTIONS:Mopenslide)
#CMAKE_CONFIGURE_ARGS+=	-DWITH_OPENSLIDE_SUPPORT=ON
#.else
#CMAKE_CONFIGURE_ARGS+=	-DWITH_OPENSLIDE_SUPPORT=OFF
#.endif

###
### Use libjpeg-turbo
### Not enabled by default as it conflicts with graphics/jpeg
###
.if !empty(PKG_OPTIONS:Mjpegturbo)
CMAKE_CONFIGURE_ARGS+= 	-DWITH_TURBOJPEG=ON
.include "../../graphics/libjpeg-turbo/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+= 	-DWITH_TURBOJPEG=OFF
.endif
