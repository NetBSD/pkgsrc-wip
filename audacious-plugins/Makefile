# $NetBSD: Makefile,v 1.4 2007/02/05 02:14:53 netcap Exp $
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

# From audio/bmp/Makefile:
# XXX Workaround a crash during shutdown that happens when dlclose(3)ing
# any open plugin.  libstdc++ gets dynamically linked in when the id3lib
# library is loaded, and is the one causing problems.  See PR pkg/26846
# for more information.
USE_LANGUAGES=		c c++
LDFLAGS.NetBSD+=        -lstdc++ -lm

# cdaudio plugin complains about missing OSS at runtime
LDFLAGS+=               ${LIBOSSAUDIO}

CONFIGURE_ARGS+= 	--disable-jack --disable-adplug --disable-lirc \
		 	--disable-amidiplug --disable-arts --disable-wma \
			--disable-timidity

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
RAWPART_cmd=            /sbin/sysctl -n kern.rawpartition | ${TR} 0-9 a-j
CONFIGURE_ARGS+=        --with-dev-dsp=${DEVOSSSOUND:Q}                 \
                        --with-cdda-device=/dev/rcd0${RAWPART_cmd:sh}   \
                        --with-cdda-dir=/cdrom/
.endif

.if ${OPSYS} == "Linux"
.	include	"../../wip/alsa-lib/buildlink3.mk"
.endif

CONFIGURE_ENV+=  	LDFLAGS="-L${LOCALBASE}/lib" \
                	CFLAGS="-I${LOCALBASE}/include/audacious"

BUILD_DEPENDS+=		audacious-[0-9]*:../../wip/audacious

.include "../../wip/audacious/buildlink3.mk"
.include "../../wip/libnms/buildlink3.mk"
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
