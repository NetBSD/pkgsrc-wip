# $NetBSD: options.mk,v 1.2 2005/11/01 22:23:58 leonardschmidt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.graveman
PKG_SUPPORTED_OPTIONS=	debug flac mp3 ogg
PKG_SUGGESTED_OPTIONS=	flac mp3 ogg

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--disable-debug
.endif

.if !empty(PKG_OPTIONS:Mflac)
.  include "../../audio/flac/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-flac
.else
CONFIGURE_ARGS+=	--disable-flac
.endif

.if !empty(PKG_OPTIONS:Mmp3)
DEPENDS+=		sox>12:../../audio/sox
.  include "../../audio/libid3tag/buildlink3.mk"
.  include "../../audio/libmad/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-mp3
.else
CONFIGURE_ARGS+=	--disable-mp3
.endif

.if !empty(PKG_OPTIONS:Mogg)
.  include "../../audio/libvorbis/buildlink3.mk"
.  include "../../multimedia/libogg/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-ogg
.else
CONFIGURE_ARGS+=	--disable-ogg
.endif
