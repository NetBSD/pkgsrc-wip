# $NetBSD: Makefile,v 1.24 2007/12/09 10:05:20 netcap Exp $
#

DISTNAME=		audacious-plugins-1.4.2
#PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		http://distfiles.atheme.org/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://audacious-media-player.org/
COMMENT=		Plugins for Audacious media player

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool pkg-config
USE_LIBTOOL=		yes

# Another ugly solution.
# This should avoid an error like: libstdc++.so.6: Undefined PLT symbol "_Unwind_GetIP" on NetBSD i386 and maybe amd64, with gcc4 at least.
# This seems to happen when libstdc++ gets linked in with the plug-ins and the code is not compiled with g++.
# For a similar problem see http://archive.netbsd.se/?ml=netbsd-java&a=2007-08&m=4912662 :
LDFLAGS.NetBSD+=	-lgcc_s

# From audio/bmp/Makefile:
# XXX Workaround a crash during shutdown that happens when dlclose(3)ing
# any open plugin.  libstdc++ gets dynamically linked in when the id3lib
# library is loaded, and is the one causing problems.  See PR pkg/26846
# for more information.
USE_LANGUAGES=		c c++
LDFLAGS.NetBSD+=	-lstdc++ -lm

# cdaudio plugin complains about missing OSS at runtime
LDFLAGS+=		${LIBOSSAUDIO}

# do not use pkgsrc' flac if it is installed
CFLAGS+=	-I. -I../flacng -Ilibflacng

CONFIGURE_ARGS+=	--disable-amidiplug --disable-evdevplug \
			--disable-coreaudio --disable-projectm \
			--disable-sid --disable-gnomeshortcuts

PKG_OPTIONS_VAR=	PKG_OPTIONS.audacious-plugins
PKG_SUPPORTED_OPTIONS=	arts esound inet6 jack midi pulse

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Marts)
.  include "../../audio/arts/buildlink3.mk"
PLIST_SUBST+=		ARTS=""
.else
CONFIGURE_ARGS+=	--disable-arts
PLIST_SUBST+=		ARTS="@comment "
.endif

.if !empty(PKG_OPTIONS:Mesound)
.  include "../../audio/esound/buildlink3.mk"
PLIST_SUBST+=		ESD=""
.else
CONFIGURE_ARGS+=	--disable-esd
PLIST_SUBST+=		ESD="@comment "
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mjack)
.  include "../../audio/jack/buildlink3.mk"
PLIST_SUBST+=		JACK=""
.else
CONFIGURE_ARGS+=	--disable-jack
PLIST_SUBST+=		JACK="@comment "
.endif

.if !empty(PKG_OPTIONS:Mmidi)
BUILD_DEPENDS+=		timidity>=0:../../audio/timidity
PLIST_SUBST+=		MIDI=""
.else
CONFIGURE_ARGS+=	--disable-timidity
PLIST_SUBST+=		MIDI="@comment "
.endif

.if !empty(PKG_OPTIONS:Mpulse)
.  include "../../wip/pulseaudio/buildlink3.mk"
PLIST_SUBST+=		PULSE=""
.else
CONFIGURE_ARGS+=	--disable-pulse
PLIST_SUBST+=		PULSE="@comment "
.endif

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
RAWPART_cmd=		/sbin/sysctl -n kern.rawpartition | ${TR} 0-9 a-j
CONFIGURE_ARGS+=	--with-dev-dsp=${DEVOSSSOUND}			\
			--with-cdda-device=/dev/rcd0${RAWPART_cmd:sh}	\
			--with-cdda-dir=/cdrom/
PLIST_SUBST+=		OSS=""
PLIST_SUBST+=		SUN=""
.elif ${OPSYS} == "FreeBSD"
PLIST_SUBST+=		OSS=""
PLIST_SUBST+=		SUN="@comment "
.elif ${OPSYS} == "DragonFly"
PLIST_SUBST+=		OSS=""
PLIST_SUBST+=		SUN="@comment "
.elif ${OPSYS} == "SunOS"
PLIST_SUBST+=		OSS="@comment "
PLIST_SUBST+=		SUN=""
.elif ${OPSYS} == "Linux"
.  include	"../../wip/alsa-lib/buildlink3.mk"
PKG_SUPPORTED_OPTIONS+= lirc
.  if !empty(PKG_OPTIONS:Mlirc)
CONFIGURE_ARGS+=	--enable-lirc
.    include "../../wip/lirc/buildlink3.mk"
.  endif
.endif

.include "../../wip/audacious/buildlink3.mk"
.include "../../wip/libmtp/buildlink3.mk"
.include "../../audio/libcddb/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libmpcdec/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../audio/wavpack/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../devel/libbinio/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../net/libmms/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/neon/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
