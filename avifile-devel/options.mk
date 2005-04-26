# $NetBSD: options.mk,v 1.2 2005/04/26 10:54:12 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.avifile-devel
PKG_SUPPORTED_OPTIONS=	sdl faad qt vorbis xvid mad a52 lame jpeg ac3_passthrough
PKG_DEFAULT_OPTIONS+=	sdl xvid vorbis mad jpeg a52

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msdl)
.include "../../devel/SDL/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sdl-prefix=${BUILDLINK_PREFIX.SDL}
.else
CONFIGURE_ARGS+=	--without-sdl
.endif

# .if !empty(PKG_OPTIONS:Mfreetype2)
# .include "../../graphics/freetype2/buildlink3.mk"
# CONFIGURE_ARGS+=	--enable-freetype2 \
# 			--with-ft-prefix=${BUILDLINK_PREFIX.freetype2}
# .else
# CONFIGURE_ARGS+=	--disable-freetype2 \
# 			--without-ft-prefix \
# 			--without-ft-exec-prefix
# .endif

# .if !empty(PKG_OPTIONS:Mxft)
# .include "../../fonts/Xft2/buildlink3.mk"
# CONFIGURE_ARGS+=	--enable-xft
# .else
# CONFIGURE_ARGS+=	--disable-xft \
# 			--without-xft-config
# .endif

.if !empty(PKG_OPTIONS:Mfaad)
.include "../../audio/faad2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-faad-prefix=${BUILDLINK_PREFIX.faad}
.else
CONFIGURE_ARGS+=	--without-faad-prefix
.endif

.if !empty(PKG_OPTIONS:Mqt)
.include "../../x11/qt3-libs/buildlink3.mk"
CONFIGURE_ARGS+=	--with-qt-prefix=${QTDIR}
PLIST_SUBST+=		QT_COMMENT=
.else
CONFIGURE_ARGS+=	--without-qt
PLIST_SUBST+=		QT_COMMENT="@comment "
SUBST_CLASSES+=		qtman
SUBST_STAGE.qtman=	pre-configure
SUBST_MESSAGE.qtman=	do not install man page for qt
SUBST_FILES.qtman=	doc/Makefile.in
SUBST_SED.qtman=	-e 's|aviplay.1||' -e 's|avirecompress.1||'
.endif

.if !empty(PKG_OPTIONS:Mvorbis)
.include "../../audio/libvorbis/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-vorbis \
			--with-vorbis-prefix=${BUILDLINK_PREFIX.libvorbis}
PLIST_SUBST+=		VORBIS_COMMENT=
.else
CONFIGURE_ARGS+=	--disable-vorbis \
			--without-vorbis-prefix
PLIST_SUBST+=		VORBIS_COMMENT="@comment "
.endif

.if !empty(PKG_OPTIONS:Mxvid)
.include "../../multimedia/xvidcore/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-xvid4 \
			--with-xvid4-prefix=${BUILDLINK_PREFIX.xvidcore}
PLIST_SUBST+=		XVID_COMMENT=
SUBST_CLASSES+=		xvidlib
SUBST_STAGE.xvidlib=	pre-configure
SUBST_MESSAGE.xvidlib=	add -lm to XVID4LIBS
SUBST_FILES.xvidlib=	configure
SUBST_SED.xvidlib=	-e 's|XVID4_LIBS -lxvidcore|XVID4_LIBS -Wl,-lxvidcore -lm|'
.else
CONFIGURE_ARGS+=	--disable-xvid4 \
			--without-xvid4-prefix
PLIST_SUBST+=		XVID_COMMENT="@comment "
.endif

.if !empty(PKG_OPTIONS:Mmad)
.include "../../audio/libmad/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-libmad
PLIST_SUBST+=		MAD_COMMENT=
.else
CONFIGURE_ARGS+=	--disable-mad
PLIST_SUBST+=		MAD_COMMENT="@comment "
.endif

# .if !empty(PKG_OPTIONS:Mvidix)
# CONFIGURE_ARGS+=	--enable-vidix
# PLIST_SUBST+=		VIDIX_COMMENT=
# .else
# CONFIGURE_ARGS+=	--disable-vidix
# PLIST_SUBST+=		VIDIX_COMMENT="@comment "
# .endif

.if !empty(PKG_OPTIONS:Ma52)
.include "../../audio/liba52/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-a52 --enable-ffmpeg-a52 \
			--with-a52-prefix=${BUILDLINK_PREFIX.liba52}
.else
CONFIGURE_ARGS+=	--disable-a52
.endif

.if !empty(PKG_OPTIONS:Mlame)
.include "../../audio/lame/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-lame-bin
PLIST_SUBST+=		LAME_COMMENT=
.else
CONFIGURE_ARGS+=	--disable-lame-bin
PLIST_SUBST+=		LAME_COMMENT="@comment "
.endif

.if !empty(PKG_OPTIONS:Mac3_passthrough)
CONFIGURE_ARGS+=	--enable-ac3passthrough
PLIST_SUBST+=		AC3PASS_COMMENT=
.else
CONFIGURE_ARGS+=	--disable-ac3passthrough
PLIST_SUBST+=		AC3PASS_COMMENT="@comment "
.endif

.if !empty(PKG_OPTIONS:Mjpeg)
.include "../../graphics/jpeg/buildlink3.mk"
PLIST_SUBST+=		JPEG_COMMENT=
.else
PLIST_SUBST+=		JPEG_COMMENT="@comment "
.endif
