# $NetBSD: Makefile,v 1.5 2005/11/19 15:41:58 leonardschmidt Exp $
#

.include "Makefile.common"

COMMENT+=	(using GStreamer)

CONFLICTS+=	bmpx-xine-[0-9]*

DEPENDS+=		gst-plugins-flac>=0.8.1:../../audio/gst-plugins-flac
DEPENDS+=		gst-plugins-mad>=0.8.1:../../audio/gst-plugins-mad
DEPENDS+=		gst-plugins-ogg>=0.8.1:../../multimedia/gst-plugins-ogg
DEPENDS+=		gst-plugins-theora>=0.8.1:../../multimedia/gst-plugins-theora
DEPENDS+=		gst-plugins-vorbis>=0.8.1:../../audio/gst-plugins-vorbis

CONFIGURE_ARGS+=	--enable-gst
CONFIGURE_ARGS+=	--disable-xine

BROKEN=			This needs GStreamer >= 0.9.1

.include "../../multimedia/gst-plugins/buildlink3.mk"
.include "../../multimedia/gstreamer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
