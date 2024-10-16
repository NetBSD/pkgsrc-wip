# $NetBSD: $

PKG_OPTIONS_VAR=		PKG_OPTIONS.kmscube

PKG_SUPPORTED_OPTIONS=		gstreamer

.include "../../mk/bsd.options.mk"

#
# GStreamer support
#
.if !empty(PKG_OPTIONS:Mgstreamer)
.  include "../../multimedia/gstreamer1/buildlink3.mk"
.  include "../../multimedia/gst-plugins1-base/buildlink3.mk"
MESON_ARGS+=	-Dgstreamer=enabled
.else
MESON_ARGS+=	-Dgstreamer=disabled
.endif
