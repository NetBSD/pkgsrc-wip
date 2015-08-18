# $NetBSD: Makefile,v 1.1 2015/08/18 20:38:11 yhardy Exp $
#

GST_PLUGINS1_NAME=	modplug
GST_PLUGINS1_DIRS=	ext/modplug
GST_PLUGINS1_FLAGS=	modplug

USE_LANGUAGES=		c c++

.include "../../multimedia/gst-plugins1-bad/Makefile.common"

.include "../../audio/libmodplug/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
