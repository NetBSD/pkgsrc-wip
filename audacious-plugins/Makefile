# $NetBSD: Makefile,v 1.2 2007/02/01 16:33:01 netcap Exp $
#

DISTNAME=		audacious-plugins-1.2.5
CATEGORIES=		audio
MASTER_SITES=		http://audacious-media-player.org/release/
EXTRACT_SUFX=		.tgz

MAINTAINER=		jfranz@bsdprojects.net
HOMEPAGE=		http://audacious-media-player.org/
COMMENT=        	Plugins for Audacious media player

GNU_CONFIGURE=		yes
USE_TOOLS=      	gmake intltool pkg-config
USE_LIBTOOL=    	yes
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+= 	--disable-jack --disable-adplug --disable-lirc \
		 	--disable-amidiplug --disable-arts --disable-wma

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
CONFIGURE_ARGS+= 	--enable-alsa
.	include "../../wip/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+= 	--disable-alsa
.endif

CONFIGURE_ENV+=  	LDFLAGS="-L${LOCALBASE}/lib" \
                	CFLAGS="-I${LOCALBASE}/include/audacious"

BUILD_DEPENDS+=		audacious-[0-9]*:../../wip/audacious

.include "../../wip/audacious/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../audio/libmodplug/buildlink3.mk"
.include "../../audio/libsidplay/buildlink3.mk"
#.include "../../audio/libsidplay2/buildlink3.mk"
.include "../../audio/libmpcdec/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/esound/buildlink3.mk"
#.include "../../wip/pulseaudio/buildlink3.mk"
.include "../../wip/wavpack/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
