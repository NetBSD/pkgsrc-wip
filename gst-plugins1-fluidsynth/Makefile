# $NetBSD: Makefile,v 1.1 2015/08/10 21:32:54 yhardy Exp $
#

GST_PLUGINS1_NAME=	fluidsynth
GST_PLUGINS1_DIRS=	ext/fluidsynth
GST_PLUGINS1_FLAGS=	fluidsynth

USE_LANGUAGES=		c c++

.include "../../multimedia/gst-plugins1-bad/Makefile.common"

.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
