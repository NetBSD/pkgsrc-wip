# $NetBSD: options.mk,v 1.2 2019/06/17 08:08:31 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.deadbeef
PKG_SUPPORTED_OPTIONS=		alsa pulseaudio
PKG_SUGGESTED_OPTIONS.Linux=	alsa

PLIST_VARS+=	alsa pulse

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
PLIST.alsa=		yes
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-alsa
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
PLIST.pulse=		yes
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pulse
.endif
