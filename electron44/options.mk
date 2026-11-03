# $NetBSD: $

PKG_OPTIONS_VAR=		PKG_OPTIONS.electron
PKG_OPTIONS_REQUIRED_GROUPS=	audio
PKG_OPTIONS_GROUP.audio=	alsa pulseaudio sunaudio
PKG_SUPPORTED_OPTIONS+=		debug wayland

.if ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=		sunaudio
.else
PKG_SUGGESTED_OPTIONS+=		pulseaudio
.endif

.include "../../devel/wayland/platform.mk"
.if ${PLATFORM_SUPPORTS_WAYLAND} == "yes"
.  if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 110000 && ${X11_TYPE} == "native"
# Need libdrm >= 2.4.116 for wayland support
.  else
PKG_SUGGESTED_OPTIONS+=	wayland
.  endif
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msunaudio)
GN_ARGS+=	use_audioio=true
.else
GN_ARGS+=	use_audioio=false
.endif

.if !empty(PKG_OPTIONS:Malsa)
GN_ARGS+=	use_alsa=true
.include "../../audio/alsa-lib/buildlink3.mk"
.else
GN_ARGS+=	use_alsa=false
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
GN_ARGS+=	use_pulseaudio=true
.include "../../audio/pulseaudio/buildlink3.mk"
.else
GN_ARGS+=	use_pulseaudio=false
.endif

.if !empty(PKG_OPTIONS:Mwayland)
GN_ARGS+=	use_system_libffi=true
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/wayland/buildlink3.mk"
.else
GN_ARGS+=	ozone_platform_wayland=false
.endif

.if !empty(PKG_OPTIONS:Mdebug)
GN_FILE=		testing.gn
GN_ARGS+=		symbol_level=1
INSTALL_UNSTRIPPED=	yes
.else
GN_FILE=		release.gn
GN_ARGS+=		blink_symbol_level=0
GN_ARGS+=		symbol_level=0
GN_VERBOSE=		# empty
.endif
