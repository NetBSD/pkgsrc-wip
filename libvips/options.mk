# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.vips
PKG_SUPPORTED_OPTIONS=	jpeg png exif tiff gobject-introspection
PKG_SUGGESTED_OPTIONS=	jpeg png

.include "../../mk/bsd.options.mk"

# meson will find libs if they are installed,
# so it makes sense to explicitly disabled them
# if they are not going to be used

# libvips advises jpeg-turbo / mozjpeg
.if !empty(PKG_OPTIONS:Mjpeg)
.include "../../graphics/libjpeg-turbo/buildlink3.mk"
.else
MESON_ARGS+= -Djpeg=disabled
.endif

.if !empty(PKG_OPTIONS:Mpng)
.include "../../graphics/png/buildlink3.mk"
.else
MESON_ARGS+= -Dpng=disabled
.endif

.if !empty(PKG_OPTIONS:Mexif)
.include "../../graphics/libexif/buildlink3.mk"
.else
MESON_ARGS+= -Dexif=disabled
.endif

.if !empty(PKG_OPTIONS:Mtiff)
.include "../../graphics/tiff/buildlink3.mk"
.else
MESON_ARGS+= -Dtiff=disabled
.endif

.if !empty(PKG_OPTIONS:Mgobject-introspection)
.include "../../devel/gobject-introspection/buildlink3.mk"
.else
MESON_ARGS+= -Dintrospection=disabled
.endif

