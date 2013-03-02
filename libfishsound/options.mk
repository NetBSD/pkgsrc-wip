# $NetBSD: options.mk,v 1.2 2013/03/02 23:21:08 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libfish
PKG_SUPPORTED_OPTIONS=	flac speex valgrind vorbis
PKG_SUGGESTED_OPTIONS+=	flac speex vorbis

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mflac)
BUILDLINK_DEPMETHOD.flac=       build
.include "../../audio/flac/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-flac
.endif

.if !empty(PKG_OPTIONS:Mspeex)
.include "../../audio/speex/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-speex
.endif

.if !empty(PKG_OPTIONS:Mvalgrind)
BUILD_DEPENDS+=	valgrind-[0-9]*:../../devel/valgrind
CONFIGURE_ARGS+=	--enable-valgrind-testing
.else
CONFIGURE_ARGS+=	--disable-valgrind-testing
.endif

.if !empty(PKG_OPTIONS:Mvorbis)
.include "../../audio/libvorbis/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-vorbis
.endif
