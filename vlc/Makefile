# $NetBSD: Makefile,v 1.6 2004/01/25 02:33:48 grantbeattie Exp $
#

DISTNAME=		vlc-0.7.0
CATEGORIES=		graphics
MASTER_SITES=		http://download.videolan.org/pub/videolan/vlc/0.7.0/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.videolan.org/
COMMENT=		VideoLAN Client

USE_BUILDLINK2=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
GNU_CONFIGURE=		yes
PTHREAD_OPTS+=		require

.include "../../mk/bsd.prefs.mk"

# XXX FIXME
.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=        --disable-vcd
.endif

CONFIGURE_ARGS+=	--enable-oss
CONFIGURE_ARGS+=	--enable-dvb

# XXX FIXME
CONFIGURE_ARGS+=	--disable-arts
CONFIGURE_ARGS+=	--disable-mkv
CONFIGURE_ARGS+=	--disable-faad
CONFIGURE_ARGS+=	--disable-ffmpeg

CONFIGURE_ARGS+=	--enable-flac
CONFIGURE_ARGS+=	--enable-x11
CONFIGURE_ARGS+=	--disable-qt
CONFIGURE_ARGS+=	--disable-kde
CONFIGURE_ARGS+=	--disable-gnome
CONFIGURE_ARGS+=	--disable-gtk

WITH_DVDCSS?=		NO
BUILD_DEFS+=		WITH_DVDCSS

.if !empty(WITH_DVDCSS:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--with-dvdcss="${BUILDLINK_PREFIX.libdvdcss}"
.include "../../misc/libdvdcss/buildlink2.mk"
PLIST_SUBST+=	DVDCSS=
.else
CONFIGURE_ARGS+=	--disable-dvd
PLIST_SUBST+=	DVDCSS="@comment "
.endif

#.include "../../audio/faad2/buildlink2.mk"
.include "../../audio/flac/buildlink2.mk"
.include "../../audio/lame/buildlink2.mk"
.include "../../audio/liba52/buildlink2.mk"
.include "../../audio/libcddb/buildlink2.mk"
.include "../../audio/libid3tag/buildlink2.mk"
.include "../../audio/libmad/buildlink2.mk"
.include "../../audio/libogg/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../audio/speex/buildlink2.mk"
.include "../../converters/fribidi/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
#.include "../../graphics/ffmpeg/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/libdvbpsi/buildlink2.mk"
.include "../../graphics/libmpeg2/buildlink2.mk"
.include "../../graphics/libmpeg2/buildlink2.mk"
.include "../../misc/libcdio/buildlink2.mk"
.include "../../misc/libdvdplay/buildlink2.mk"
.include "../../misc/libdvdread/buildlink2.mk"
.include "../../net/openslp/buildlink2.mk"
.include "../../x11/wxGTK/buildlink2.mk"

.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
