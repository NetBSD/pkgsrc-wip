PKG_OPTIONS_VAR=	PKG_OPTIONS.csound6


PKG_OPTIONS_VAR=	PKG_OPTIONS.portmidi
PKG_SUPPORTED_OPTIONS=	alsa

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "Linux"
PKG_SUPPORTED_OPTIONS+=	alsa
PKG_SUGGESTED_OPTIONS+=	alsa
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		alsa
.if !empty(PKG_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
.endif
