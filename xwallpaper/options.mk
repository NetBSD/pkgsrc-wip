# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.xwallpaper
PKG_SUPPORTED_OPTIONS=	jpeg png
PKG_SUGGESTED_OPTIONS=	png

.include "../../mk/bsd.options.mk"

# untested, failed to build with jpeg-9d
JPEG_ACCEPTED=libjpeg-turbo
.if !empty(PKG_OPTIONS:Mjpeg)
.include "../../mk/jpeg.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpng)
.include "../../graphics/png/buildlink3.mk"
.endif
