# $NetBSD: options.mk,v 1.32 2016/08/20 11:17:32 ryoon Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.chromium
PKG_OPTIONS_REQUIRED_GROUPS=	audio
PKG_OPTIONS_GROUP.audio=	alsa pulseaudio
PKG_SUPPORTED_OPTIONS+=		debug
PKG_SUGGESTED_OPTIONS=		pulseaudio

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
GN_ARGS+=	use_alsa=true
GN_ARGS+=	use_pulseaudio=false
.include "../../audio/alsa-lib/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mpulseaudio)
GN_ARGS+=	use_alsa=false
GN_ARGS+=	use_pulseaudio=true
.include "../../audio/pulseaudio/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mdebug)
BUILDTYPE=		Debug
GN_ARGS+=		is_debug=true
# Dynamic link build causes link errors in pkgsrc.
GN_ARGS+=		is_component_build=false
GN_BOOTSTRAP_FLAGS+=	--debug
#GN_VERBOSE=		-v
.else
BUILDTYPE=		Release
GN_ARGS+=		is_debug=false \
			symbol_level=0 \
			remove_webcore_debug_symbols=true
.endif
