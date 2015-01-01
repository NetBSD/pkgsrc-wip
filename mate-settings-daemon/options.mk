# $NetBSD: options.mk,v 1.1 2015/01/01 08:25:54 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mate-settings-daemon
PKG_OPTIONS_OPTIONAL_GROUPS+=	audio
PKG_OPTIONS_GROUP.audio=	pulseaudio gstreamer
PKG_SUGGESTED_OPTIONS=	gstreamer

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pulse
.else
CONFIGURE_ARGS+=	--disable-pulse
.endif

.if !empty(PKG_OPTIONS:Mgstreamer)
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gstreamer
.else
CONFIGURE_ARGS+=	--disable-gstreamer
.endif
