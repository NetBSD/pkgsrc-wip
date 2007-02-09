# $NetBSD: options.mk,v 1.1 2007/02/09 12:16:42 bsadewitz Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.jack
PKG_SUPPORTED_OPTIONS+=	portaudio sndfile flac
PKG_SUGGESTED_OPTIONS+=	sndfile flac

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mportaudio)
.include "../../audio/portaudio/buildlink3.mk"
CONFIGURE_ARGS+=	--with-portaudio
.else
CONFIGURE_ARGS+=	--without-portaudio
.endif

.if !empty(PKG_OPTIONS:Msndfile)
.include "../../audio/libsndfile/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libsndfile
.else
CONFIGURE_ARGS+=	--without-libsndfile
.endif

.if !empty(PKG_OPTIONS:Mflac)
.include "../../audio/flac/buildlink3.mk"
CONFIGURE_ARGS+=	--with-flac
.else
CONFIGURE_ARGS+=	--without-flac
.endif
