# $NetBSD: Makefile,v 1.34 2012/05/19 06:11:15 lokivit Exp $
#

DISTNAME=	audacious-plugins-3.2.2
CATEGORIES=	wip
MASTER_SITES=	http://distfiles.audacious-media-player.org/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	loki.vt@gmail.com
HOMEPAGE=	http://audacious-media-player.org/
COMMENT=	Plugins for Audacious media player
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=  c c++
GNU_CONFIGURE=  yes
USE_TOOLS+=     gmake pkg-config
USE_LIBTOOL=    yes
CFLAGS+=	-I. -I../flacng -Ilibflacng -I${BUILDLINK_PREFIX.SDL}/include/SDL

CONFIGURE_ARGS+=	--disable-amidiplug --disable-gnomeshortcuts
.include "options.mk"
.include "../../mk/bsd.prefs.mk"

.include "../../wip/audacious/buildlink3.mk"
.include "../../wip/libmpg123/buildlink3.mk"
#.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../audio/libmodplug/buildlink3.mk"
.include "../../audio/libcddb/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libmpcdec/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../audio/wavpack/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../devel/libbinio/buildlink3.mk"
.include "../../devel/libmtp/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../net/libmms/buildlink3.mk"
#.include "../../www/curl/buildlink3.mk"
.include "../../www/neon/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
#.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
