# $NetBSD options.mk $

PKG_OPTIONS_VAR=        PKG_OPTIONS.ffmpeg-snapshot
PKG_SUPPORTED_OPTIONS=  old-dist i686 gsm mp3lame libogg xvid vorbis faad faac x264 a52
PKG_SUGGESTED_OPTIONS=  i686 mp3lame libogg faac a52

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mold-dist)
TODAY=	${DISTDATE}
.endif

.if !empty(PKG_OPTIONS:Mi686)
CONFIGURE_ARGS+=	--cpu=i686
.endif

.if !empty(PKG_OPTIONS:Mgsm)
CONFIGURE_ARGS+=	--enable-libgsm
.include "../../audio/gsm/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmp3lame)          
CONFIGURE_ARGS+=	--enable-mp3lame
.include "../../audio/lame/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibogg)
CONFIGURE_ARGS+=        --enable-libogg
.include "../../multimedia/libogg/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mxvid)       
CONFIGURE_ARGS+=        --enable-xvid
.include "../../multimedia/xvidcore/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mvorbis)
CONFIGURE_ARGS+=        --enable-vorbis
.include "../../audio/libvorbis/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mfaad)
CONFIGURE_ARGS+=        --enable-faad
.include "../../audio/faad2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mfaac)
CONFIGURE_ARGS+=        --enable-faac
.include "../../audio/faac/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mx264)
CONFIGURE_ARGS+=        --enable-x264
.include "../../multimedia/x264-devel/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Ma52)
CONFIGURE_ARGS+=        --enable-a52
.include "../../audio/liba52/buildlink3.mk"
.endif

