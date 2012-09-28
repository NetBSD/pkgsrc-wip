# $NetBSD: Makefile,v 1.3 2012/09/28 21:24:31 asau Exp $
#

DISTNAME=	deadbeef-0.5.2
CATEGORIES=	audio
MASTER_SITES=	http://sourceforge.net/projects/deadbeef/files/
EXTRACT_SUFX=	.tar.bz2
PKGREVISION=	1

MAINTAINER=	dieter.NetBSD@pandora.be
HOMEPAGE=	http://deadbeef.sourceforge.net/
COMMENT=	Ultimate Music Player For GNU/Linux
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake intltool pkg-config

LDFLAGS+=	-lintl
MAKE_ENV+=	OSS_LIBS=${LIBOSSAUDIO}

BUILD_DEPENDS+=	yasm-[0-9]*:../../devel/yasm

.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libcddb/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
