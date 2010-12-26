# $NetBSD: options.mk,v 1.2 2010/12/26 05:01:23 davesainty Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.synfig

PKG_SUPPORTED_OPTIONS=	\
	png \
	mng \
	jpeg \
	freetype \
	fontconfig \
	openexr \
	libavcodec
# TODO: libmagick++
# TODO: vimage (MacOS X only)

PKG_SUGGESTED_OPTIONS=	\
	png \
	jpeg \
	freetype \
	fontconfig

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpng)
.include "../../graphics/png/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmng)
.include "../../graphics/mng/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mjpeg)
.include "../../mk/jpeg.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mfreetype)
.include "../../graphics/freetype2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mfontconfig)
.include "../../fonts/fontconfig/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mopenexr)
.include "../../graphics/openexr/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibavcodec)
.include "../../multimedia/ffmpeg/buildlink3.mk"
.endif
