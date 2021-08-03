# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.timg
PKG_SUPPORTED_OPTIONS+=	graphicsmagick turbojpeg

PKG_SUGGESTED_OPTIONS=	graphicsmagick

.include "../../mk/bsd.options.mk"

###
### Use GraphicsMagick
###
.if !empty(PKG_OPTIONS:Mgraphicsmagick)
.include "../../graphics/GraphicsMagick/buildlink3.mk"
.endif

###
### Use OpenSlide - Not yet in pkgsrc, so disabled
###
#.if !empty(PKG_OPTIONS:Mopenslide)
#CMAKE_ARGS+=	-DWITH_OPENSLIDE_SUPPORT=ON
#.else
#CMAKE_ARGS+=	-DWITH_OPENSLIDE_SUPPORT=OFF
#.endif

###
### Use turbojpeg
### Not enabled by default as it conflicts with graphics/jpeg
###
.if !empty(PKG_OPTIONS:Mturbojpeg)
CMAKE_ARGS+= 	-DWITH_TURBOJPEG=ON
.include "../../graphics/libjpeg-turbo/buildlink3.mk"
.else
CMAKE_ARGS+= 	-DWITH_TURBOJPEG=OFF
.endif
