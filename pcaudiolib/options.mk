# $NetBSD: $

PKG_OPTIONS_VAR=		PKG_OPTIONS.pcaudiolib

PKG_SUPPORTED_OPTIONS+=		alsa pulseaudio sun
PKG_SUGGESTED_OPTIONS.Linux+=	alsa
PKG_SUGGESTED_OPTIONS.NetBSD+=	sun

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msun)
CONFIGURE_ARGS+=	--with-sun
CFLAGS+=		-D_SUNAUDIO
.else
CONFIGURE_ARGS+=	--without-sun
.endif

.if !empty(PKG_OPTIONS:Malsa)
.  include "../../audio/alsa-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--with-alsa
.else
CONFIGURE_ARGS+=	--without-alsa
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
.  include "../../audio/pulseaudio/buildlink3.mk"
CONFIGURE_ARGS+=	--with-pulseaudio
.else
CONFIGURE_ARGS+=	--without-pulseaudio
.endif
