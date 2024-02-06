# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.fim

PKG_SUPPORTED_OPTIONS+= aalib caca debug dia exif gif inkscape jpeg \
			png sdl sdl2 jasper tiff xfig

# considered 'experimental' as of 0.6rc2
PKG_SUPPORTED_OPTIONS+=	djvu ps	imagemagick graphicsmagick libarchive

# broken as of 0.6rc2
#PKG_SUPPORTED_OPTIONS+=exiftool pdf imlib2

# all except experimental, broken and sdl (we have sdl2 instead)
PKG_SUGGESTED_OPTIONS+= aalib caca debug dia exif gif inkscape jpeg \
			png sdl2 jasper tiff xfig

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Maalib)
CONFIGURE_ARGS+=	--enable-aa
.include "../../graphics/aalib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-aa
.endif

.if !empty(PKG_OPTIONS:Mcaca)
CONFIGURE_ARGS+=	--enable-caca
.include "../../graphics/libcaca/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-caca
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--disable-debug
.endif

.if !empty(PKG_OPTIONS:Mdia)
CONFIGURE_ARGS+=	--enable-dia
DEPENDS+=		dia-[0-9]*:../../graphics/dia
.else
CONFIGURE_ARGS+=	--disable-dia
.endif

.if !empty(PKG_OPTIONS:Mdjvu)
CONFIGURE_ARGS+=	--enable-djvu
.include "../../graphics/djvulibre-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-djvu
.endif

.if !empty(PKG_OPTIONS:Mexif)
CONFIGURE_ARGS+=	--enable-exif
.include "../../graphics/libexif/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-exif
.endif

# broken as of 0.6rc2: missing ExifTool.h
#.if !empty(PKG_OPTIONS:Mexiftool)
#CONFIGURE_ARGS+=	--enable-exiftool
#DEPENDS+=		p5-Image-ExifTool-[0-9]*:../../graphics/p5-Image-ExifTool
#.else
CONFIGURE_ARGS+=	--disable-exiftool
#.endif

.if !empty(PKG_OPTIONS:Mgif)
CONFIGURE_ARGS+=	--enable-gif
.include "../../graphics/giflib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gif
.endif

.if !empty(PKG_OPTIONS:Mgraphicsmagick)
CONFIGURE_ARGS+=	--enable-graphicsmagick
.include "../../graphics/GraphicsMagick/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-graphicsmagick
.endif

.if !empty(PKG_OPTIONS:Mimagemagick)
CONFIGURE_ARGS+=	--enable-imagemagick
DEPENDS+=		ImageMagick-[0-9]*:../../graphics/ImageMagick
.else
CONFIGURE_ARGS+=	--disable-imagemagick
.endif

# broken as of 0.6rc2: uses imlib2-config which we don't have
#.if !empty(PKG_OPTIONS:Mimlib2)
#CONFIGURE_ARGS+=	--enable-imlib2
#.include "../../graphics/imlib2/buildlink3.mk"
#.else
CONFIGURE_ARGS+=	--disable-imlib2
#.endif

.if !empty(PKG_OPTIONS:Minkscape)
CONFIGURE_ARGS+=	--enable-inkscape
DEPENDS+=		inkscape-[0-9]*:../../graphics/inkscape
.else
CONFIGURE_ARGS+=	--disable-inkscape
.endif

.if !empty(PKG_OPTIONS:Mjasper)
CONFIGURE_ARGS+=	--enable-jasper
.include "../../graphics/jasper/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-jasper
.endif

.if !empty(PKG_OPTIONS:Mjpeg)
CONFIGURE_ARGS+=	--enable-jpeg
.include "../../mk/jpeg.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-jpeg
.endif

.if !empty(PKG_OPTIONS:Mlibarchive)
CONFIGURE_ARGS+=	--enable-archive
.include "../../archivers/libarchive/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-archive
.endif

#.if !empty(PKG_OPTIONS:Mpdf)
#CONFIGURE_ARGS+=	--enable-pdf
#CONFIGURE_ARGS+=	--enable-poppler
#.include "../../print/poppler-cpp/buildlink3.mk"
#.else
CONFIGURE_ARGS+=	--disable-pdf
CONFIGURE_ARGS+=	--disable-poppler
#.endif

.if !empty(PKG_OPTIONS:Mpng)
CONFIGURE_ARGS+=	--enable-png
.include "../../graphics/png/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-png
.endif

.if !empty(PKG_OPTIONS:Mps)
CONFIGURE_ARGS+=	--enable-ps
.include "../../print/libspectre/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ps
.endif

.if !empty(PKG_OPTIONS:Msdl2)
CONFIGURE_ARGS+=	--enable-sdl=2
.include "../../devel/SDL2/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=	--enable-sdl=1
.include "../../devel/SDL/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-sdl
.endif

.if !empty(PKG_OPTIONS:Mtiff)
CONFIGURE_ARGS+=	--enable-tiff
.include "../../graphics/tiff/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-tiff
.endif

.if !empty(PKG_OPTIONS:Mxfig)
CONFIGURE_ARGS+=	--enable-xfig
DEPENDS+=		xfig-[0-9]*:../../graphics/xfig
.else
CONFIGURE_ARGS+=	--disable-xfig
.endif
