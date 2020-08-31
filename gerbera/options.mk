# $NetBSD$
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.gerbera

PKG_SUPPORTED_OPTIONS=	debug ffmpeg ffmpegthumbnailer javascript lastfm systemd

PKG_SUGGESTED_OPTIONS=	ffmpegthumbnailer javascript

.include "../../mk/bsd.options.mk"

.if empty(PKG_OPTIONS:Mdebug)
CMAKE_ARGS+=	-DWITH_DEBUG=OFF
.endif

.if !empty(PKG_OPTIONS:Mffmpeg)
CMAKE_ARGS+=	-DWITH_AVCODEC=ON

.  include "../../multimedia/ffmpeg4/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mffmpegthumbnailer)
CMAKE_ARGS+=	-DWITH_FFMPEGTHUMBNAILER=ON

.  include "../../multimedia/ffmpegthumbnailer/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlastfm)
CMAKE_ARGS+=	-DWITH_LASTFM=ON

.  include "../../audio/liblastfm/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mjavascript)
CMAKE_ARGS+=	-DWITH_JS=OFF

.  include "../../lang/libduktape/buildlink3.mk"
.endif

.if empty(PKG_OPTIONS:Msystemd)
CMAKE_ARGS+=	-DWITH_SYSTEMD=OFF
.endif
