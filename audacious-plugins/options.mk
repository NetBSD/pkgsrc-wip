# $NetBSD: options.mk,v 1.7 2014/10/23 13:41:00 thomasklausner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.audacious-plugins
PKG_SUPPORTED_OPTIONS=	arts esound inet6 jack pulseaudio
PKG_SUGGESTED_OPTIONS+=	inet6 pulseaudio

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	arts
.if !empty(PKG_OPTIONS:Marts)
.  include "../../audio/arts/buildlink3.mk"
PLIST.arts=	yes
.else
CONFIGURE_ARGS+=	--disable-arts
.endif

PLIST_VARS+=	esd
.if !empty(PKG_OPTIONS:Mesound)
.  include "../../audio/esound/buildlink3.mk"
PLIST.esd=	yes
.else
CONFIGURE_ARGS+=	--disable-esd
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

PLIST_VARS+=	jack
.if !empty(PKG_OPTIONS:Mjack)
.  include "../../audio/jack/buildlink3.mk"
PLIST.jack=	yes
.else
CONFIGURE_ARGS+=	--disable-jack
.endif

PLIST_VARS+=	pulse
.if !empty(PKG_OPTIONS:Mpulseaudio)
.  include "../../audio/pulseaudio/buildlink3.mk"
PLIST.pulse=	yes
.else
CONFIGURE_ARGS+=	--disable-pulse
.endif
