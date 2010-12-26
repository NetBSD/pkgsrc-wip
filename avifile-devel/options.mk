# $NetBSD: options.mk,v 1.13 2010/12/26 05:01:21 davesainty Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.avifile-devel
PKG_SUPPORTED_OPTIONS=	sdl faad qt vorbis xvid mad a52 lame jpeg ac3_passthrough
PKG_SUGGESTED_OPTIONS=	sdl xvid vorbis mad jpeg a52

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "amd64"
PKG_SUPPORTED_OPTIONS+=	mmx
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msdl)
.include "../../devel/SDL/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sdl-prefix=${BUILDLINK_PREFIX.SDL:Q}
.else
CONFIGURE_ARGS+=	--without-sdl
.endif

# .if !empty(PKG_OPTIONS:Mfreetype2)
# .include "../../graphics/freetype2/buildlink3.mk"
# CONFIGURE_ARGS+=	--enable-freetype2 \
# 			--with-ft-prefix=${BUILDLINK_PREFIX.freetype2:Q}
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
CONFIGURE_ARGS+=	--with-faad-prefix=${BUILDLINK_PREFIX.faad:Q}
.else
CONFIGURE_ARGS+=	--without-faad-prefix
.endif

.if !empty(PKG_OPTIONS:Mqt)
.include "../../x11/qt3-libs/buildlink3.mk"
CONFIGURE_ARGS+=	--with-qt-prefix=${QTDIR:Q}
PLIST.qt=		yes
.else
CONFIGURE_ARGS+=	--without-qt
SUBST_CLASSES+=		qtman
SUBST_STAGE.qtman=	pre-configure
SUBST_MESSAGE.qtman=	do not install man page for qt
SUBST_FILES.qtman=	doc/Makefile.in
SUBST_SED.qtman=	-e 's|aviplay.1||'
SUBST_SED.qtman+=	-e 's|avirecompress.1||'
.endif

.if !empty(PKG_OPTIONS:Mvorbis)
.include "../../audio/libvorbis/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-vorbis \
			--with-vorbis-prefix=${BUILDLINK_PREFIX.libvorbis:Q}
PLIST.vorbis=		yes
.else
CONFIGURE_ARGS+=	--disable-vorbis \
			--without-vorbis-prefix
.endif

.if !empty(PKG_OPTIONS:Mxvid)
.include "../../multimedia/xvidcore/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-xvid4 \
			--with-xvid4-prefix=${BUILDLINK_PREFIX.xvidcore:Q}
PLIST.xvid=		yes

SUBST_CLASSES+=		xvidlib
SUBST_STAGE.xvidlib=	pre-configure
SUBST_MESSAGE.xvidlib=	add -lm to XVID4LIBS
SUBST_FILES.xvidlib=	configure
SUBST_SED.xvidlib=	-e 's|XVID4_LIBS -lxvidcore|XVID4_LIBS -Wl,-lxvidcore -lm|'

.else
CONFIGURE_ARGS+=	--disable-xvid4 \
			--without-xvid4-prefix
.endif

.if !empty(PKG_OPTIONS:Mmad)
.include "../../audio/libmad/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-libmad
PLIST.mad=		yes
.else
CONFIGURE_ARGS+=	--disable-mad
.endif

# .if !empty(PKG_OPTIONS:Mvidix)
# CONFIGURE_ARGS+=	--enable-vidix
# PLIST.vidix=		yes
# .else
# CONFIGURE_ARGS+=	--disable-vidix
# .endif

.if !empty(PKG_OPTIONS:Ma52)
.include "../../audio/liba52/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-a52 --enable-ffmpeg-a52 \
			--with-a52-prefix=${BUILDLINK_PREFIX.liba52:Q}
PLIST.ffmpeg=		yes
.else
CONFIGURE_ARGS+=	--disable-a52
.endif

.if !empty(PKG_OPTIONS:Mlame)
.include "../../audio/lame/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-lame-bin
PLIST.lame=		yes
.else
CONFIGURE_ARGS+=	--disable-lame-bin
.endif

.if !empty(PKG_OPTIONS:Mac3_passthrough)
.include "../../mk/oss.buildlink3.mk"
.  if ${OSS_TYPE} == "none"
PKG_FAIL_REASON+=	"Need oss to use ac3passthrough"
.  else
CONFIGURE_ARGS+=	--enable-ac3passthrough
PLIST.ac3pass=		yes
.  endif
.else
CONFIGURE_ARGS+=	--disable-ac3passthrough
.endif

.if !empty(PKG_OPTIONS:Mjpeg)
.include "../../mk/jpeg.buildlink3.mk"
PLIST.jpeg=		yes
.endif

.if !empty(PKG_OPTIONS:Mmmx)
CONFIGURE_ARGS+=	--enable-x86opt
.else
CONFIGURE_ARGS+=	--disable-x86opt
.endif

#.if !empty(PKG_OPTIONS:Mv4l)
#.include "../../graphics/libv4l/buildlink3.mk"
#CONFIGURE_ARGS+=	--enable-v4l
#PLIST.v4l=		yes
#.  if !exists(/usr/include/linux/videodev.h)
#pre-configure: fix-videodev
#fix-videodev:
#	${MKDIR} ${BUILDLINK_DIR}/include/linux
#	cp ../../graphics/libv4l/files/videodev.h ${BUILDLINK_DIR}/include/linux/videodev.h
#.  endif
#.else
#CONFIGURE_ARGS+=	--disable-v4l
#SUBST_CLASSES+=		v4l
#SUBST_STAGE.v4l=	pre-configure
#SUBST_MESSAGE.v4l=	do not support v4l, so do not build qtvidcap
#SUBST_FILES.v4l=	samples/Makefile.in
#SUBST_SED.v4l=		-E -e 's|^(SUBDIRS.+)qtvidcap|\1|'
#
#SUBST_CLASSES+=		v4lman
#SUBST_STAGE.v4lman=	pre-configure
#SUBST_MESSAGE.v4lman=	do not install man page for v4l
#SUBST_FILES.v4lman=	doc/Makefile.in
#SUBST_SED.v4lman=	-e 's|kv4lsetup.1||'
#SUBST_SED.v4lman+=	-e 's|avirec.1||'
#.endif
