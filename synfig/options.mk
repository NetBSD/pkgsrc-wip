# $NetBSD: options.mk,v 1.3 2011/03/21 16:43:49 phonohawk Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.synfig

PKG_SUPPORTED_OPTIONS=	\
	mng \
	jpeg \
	freetype \
	fontconfig \
	openexr \
	ffmpeg \
	imagemagick

PKG_SUGGESTED_OPTIONS=	\
	jpeg \
	freetype \
	fontconfig

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

# NOTE: libpng is in fact optional for synfig, but synfigstudio
# requires synfig's PNG support to build.

PRINT_PLIST_AWK+= \
	/^lib\/synfig\/modules\/libmod_mng\.la$$/ { print "$${PLIST.mng}" $$0; next; }
PLIST_VARS+=	mng
.if !empty(PKG_OPTIONS:Mmng)
.include "../../graphics/mng/buildlink3.mk"
PLIST.mng=	yes
.endif

PRINT_PLIST_AWK+= \
	/^lib\/synfig\/modules\/libmod_jpeg\.la$$/ { print "$${PLIST.jpeg}" $$0; next; }
PLIST_VARS+=	jpeg
.if !empty(PKG_OPTIONS:Mjpeg)
.include "../../mk/jpeg.buildlink3.mk"
PLIST.jpeg=	yes
.endif

PRINT_PLIST_AWK+= \
	/^lib\/synfig\/modules\/liblyr_freetype\.la$$/ { print "$${PLIST.freetype}" $$0; next; }
PLIST_VARS+=	freetype
.if !empty(PKG_OPTIONS:Mfreetype)
.include "../../graphics/freetype2/buildlink3.mk"
PLIST.freetype=	yes
.endif

.if !empty(PKG_OPTIONS:Mfontconfig)
.include "../../fonts/fontconfig/buildlink3.mk"
.endif

PRINT_PLIST_AWK+= \
	/^lib\/synfig\/modules\/libmod_openexr\.la$$/ { print "$${PLIST.openexr}" $$0; next; }
PLIST_VARS+=	openexr
.if !empty(PKG_OPTIONS:Mopenexr)
.include "../../graphics/openexr/buildlink3.mk"
PLIST.openexr=	yes
.endif

PRINT_PLIST_AWK+= \
	/^lib\/synfig\/modules\/libmod_ffmpeg\.la$$/ { print "$${PLIST.ffmpeg}" $$0; next; }
PLIST_VARS+=	ffmpeg
.if !empty(PKG_OPTIONS:Mffmpeg)
.include "../../multimedia/ffmpeg/buildlink3.mk"
PLIST.ffmpeg=	yes
.endif

PRINT_PLIST_AWK+= \
	/^lib\/synfig\/modules\/libmod_imagemagick\.la$$/ { print "$${PLIST.imagemagick}" $$0; next; }
PLIST_VARS+=	imagemagick
.if !empty(PKG_OPTIONS:Mimagemagick)
.include "../../graphics/ImageMagick/buildlink3.mk"
PLIST.imagemagick=	yes
.else
CONFIGURE_ARGS+=	--without-imagemagick
.endif
