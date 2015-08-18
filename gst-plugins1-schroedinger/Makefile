# $NetBSD: Makefile,v 1.1 2015/08/18 20:43:31 yhardy Exp $
#

GST_PLUGINS1_NAME=	schro
GST_PLUGINS1_DIRS=	ext/schroedinger
GST_PLUGINS1_FLAGS=	schro

# omitted in gst-plugins1-bad/Makefile.common
CONFIGURE_ARGS+=	--enable-schro

USE_LANGUAGES=		c c++

.include "../../multimedia/gst-plugins1-bad/Makefile.common"

.include "../../multimedia/schroedinger/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
