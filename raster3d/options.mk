# $NetBSD: options.mk,v 1.2 2010/06/01 08:14:50 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.raster3d
PKG_SUPPORTED_OPTIONS=	imagemagick
PKG_SUGGESTED_OPTIONS=	imagemagick

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	magick

.if !empty(PKG_OPTIONS:Mimagemagick)
DEPENDS+=	ImageMagick>=5.5.4:../../graphics/ImageMagick
PLIST.magick=	yes
CFLAGS+=	-DIMAGEPIPE
.endif
