# $NetBSD: Makefile,v 1.1 2015/08/10 21:29:54 yhardy Exp $
#

GST_PLUGINS1_NAME=	ximagesrc
GST_PLUGINS1_DIRS=	sys/ximage
GST_PLUGINS1_FLAGS=	x xshm

.include "../../multimedia/gst-plugins1-good/Makefile.common"

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
