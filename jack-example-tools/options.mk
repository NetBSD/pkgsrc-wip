# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.jack-example-tools

PKG_SUPPORTED_OPTIONS=		alsa opus

PLIST_VARS+=			${PKG_SUPPORTED_OPTIONS}

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
PLIST.alsa=	yes
.include "../../audio/alsa-lib/buildlink3.mk"
.else
MESON_ARGS+=	-Dalsa_in_out=disabled
.endif

.if !empty(PKG_OPTIONS:Mopus)
PLIST.opus=	yes
.include "../../audio/libopus/buildlink3.mk"
.else
MESON_ARGS+=	-Dopus_support=disabled
.endif
