# $NetBSD: options.mk,v 1.2 2015/04/19 21:12:18 nbrkv Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.residualvm
PKG_SUPPORTED_OPTIONS=		faad flac fluidsynth mad freetype png theora timidity jpeg
PKG_SUGGESTED_OPTIONS=		faad flac fluidsynth mad freetype png theora timidity jpeg vorbis 
# only one of tremor or ogg/vorbis
PKG_OPTIONS_OPTIONAL_GROUPS+=	vorbis
PKG_OPTIONS_GROUP.vorbis=	vorbis tremor

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfaad)
CONFIGURE_ARGS+=	--enable-faad
CONFIGURE_ARGS+=	--with-faad-prefix=${BUILDLINK_PREFIX.faad2}
.include "../../audio/faad2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mflac)
CONFIGURE_ARGS+=	--enable-flac
CONFIGURE_ARGS+=	--with-flac-prefix=${BUILDLINK_PREFIX.flac}
.include "../../audio/flac/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mfluidsynth)
CONFIGURE_ARGS+=	--enable-fluidsynth
CONFIGURE_ARGS+=	--with-fluidsynth-prefix=${BUILDLINK_PREFIX.fluidsynth}
.include "../../audio/fluidsynth/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mfreetype)
CONFIGURE_ARGS+=	--enable-freetype2
#CONFIGURE_ARGS+=	--with-freetype-prefix=${BUILDLINK_PREFIX.freetype2}
.include "../../graphics/freetype2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmad)
CONFIGURE_ARGS+=	--enable-mad
CONFIGURE_ARGS+=	--with-mad-prefix=${BUILDLINK_PREFIX.libmad}
.include "../../audio/libmad/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mvorbis)
CONFIGURE_ARGS+=	--enable-vorbis
CONFIGURE_ARGS+=	--with-vorbis-prefix=${BUILDLINK_PREFIX.libvorbis}
.include "../../audio/libvorbis/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ogg-prefix=${BUILDLINK_PREFIX.libogg}
.include "../../multimedia/libogg/buildlink3.mk"
.endif

# mentioned in configure script, but seemingly not used
#.if !empty(PKG_OPTIONS:Mlibmpeg2)
#.include "../../multimedia/libmpeg2/buildlink3.mk"
#.endif

.if !empty(PKG_OPTIONS:Mpng)
CONFIGURE_ARGS+=	--enable-png
CONFIGURE_ARGS+=	--with-png-prefix=${BUILDLINK_PREFIX.png}
.include "../../graphics/png/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mjpeg)
CONFIGURE_ARGS+=	--with-jpeg-prefix=${BUILDLINK_PREFIX.jpeg}
.include "../../graphics/jpeg/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mtheora)
CONFIGURE_ARGS+=	--enable-theoradec
CONFIGURE_ARGS+=	--with-theoradec-prefix=${BUILDLINK_PREFIX.libtheora}
.include "../../multimedia/libtheora/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mtimidity)
DEPENDS+=		timidity-[0-9]*:../../audio/timidity
CONFIGURE_ARGS+=	--enable-timidity
.endif

.if !empty(PKG_OPTIONS:Mtremor)
CONFIGURE_ARGS+=	--with-tremor-prefix=${BUILDLINK_PREFIX.tremor}
CONFIGURE_ARGS+=	--enable-tremor
.include "../../audio/tremor/buildlink3.mk"
.endif
