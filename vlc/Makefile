# $NetBSD: Makefile,v 1.4 2004/01/16 11:32:22 xtraeme Exp $
#

DISTNAME=		vlc-0.7.0
CATEGORIES=		graphics
MASTER_SITES=		http://download.videolan.org/pub/videolan/vlc/0.7.0/

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.videolan.org/
COMMENT=		Video Lan Client 

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

# XXX FIXME
.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=        --disable-vcd
CONFIGURE_ARGS+=	--disable-vcdx
.endif

CONFIGURE_ARGS+=	--enable-oss
CONFIGURE_ARGS+=	--enable-dvd
CONFIGURE_ARGS+=	--enable-dvdread
CONFIGURE_ARGS+=	--enable-dvdplay

# XXX FIXME
CONFIGURE_ARGS+=	--disable-libcdio 
CONFIGURE_ARGS+=	--disable-libcddb
CONFIGURE_ARGS+=	--disable-mkv 
CONFIGURE_ARGS+=	--disable-faad
CONFIGURE_ARGS+=	--disable-ffmpeg

CONFIGURE_ARGS+=	--enable-flac
CONFIGURE_ARGS+=	--enable-x11
CONFIGURE_ARGS+=	--disable-qt
CONFIGURE_ARGS+=	--disable-kde
CONFIGURE_ARGS+=	--disable-gnome
CONFIGURE_ARGS+=	--disable-gtk

#.include "../../audio/faad2/buildlink2.mk"
.include "../../audio/flac/buildlink2.mk"
.include "../../audio/liba52/buildlink2.mk"
.include "../../audio/libmad/buildlink2.mk"
.include "../../audio/libogg/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../audio/speex/buildlink2.mk"
.include "../../converters/fribidi/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
#.include "../../graphics/ffmpeg/buildlink2.mk"
.include "../../graphics/libmpeg2/buildlink2.mk"
.include "../../misc/libdvdcss/buildlink2.mk"
.include "../../misc/libdvdplay/buildlink2.mk"
.include "../../misc/libdvdread/buildlink2.mk"
.include "../../net/openslp/buildlink2.mk"
.include "../../x11/wxGTK/buildlink2.mk"

.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
