# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.spotify-player
PKG_OPTIONS_OPTIONAL_GROUPS=	backend
PKG_OPTIONS_GROUP.backend=	alsa portaudio pulseaudio rodio

PKG_SUGGESTED_OPTIONS=	portaudio

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CARGO_FEATURES+=	alsa_backend
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.alsa-lib}/lib
.include "../../audio/alsa-lib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mportaudio)
CARGO_FEATURES+=	portaudio_backend
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.portaudio}/${BUILDLINK_LIBDIRS.portaudio}
.include "../../audio/portaudio/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CARGO_FEATURES+=	pulseaudio_backend
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.pulseaudio}/lib
.include "../../audio/pulseaudio/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mrodio)
CARGO_FEATURES+=	rodio_backend
.endif
