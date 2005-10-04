# $NetBSD: Makefile,v 1.1.1.1 2005/10/04 12:30:24 leonardschmidt Exp $
#

.include "Makefile.common"

COMMENT+=	(using GStreamer)

CONFLICTS+=	bmpx-xine-[0-9]*

CONFIGURE_ARGS+=	--enable-gst
CONFIGURE_ARGS+=	--disable-xine

BROKEN=			GStreamer 0.9 is needed

.include "../../multimedia/gst-plugins/buildlink3.mk"
.include "../../multimedia/gstreamer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
