# $NetBSD: Makefile,v 1.1.1.1 2003/04/15 18:04:10 bmeurer Exp $

DISTNAME=		gst-plugins-0.6.0
PKGNAME=		gstreamer-plugins-0.6.0
CATEGORIES=		audio devel graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gstreamer/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		benedikt.meurer@unix-ag.uni-siegen.de
HOMEPAGE=		http://www.gstreamer.net/
COMMENT=		GStreamer plugins

USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
USE_X11=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gst-libs/gst/gconf/gstreamer-gconf.pc.in
PKGCONFIG_OVERRIDE=	${WRKSRC}/pkgconfig/gstreamer-libs.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/pkgconfig/gstreamer-play.pc.in

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-oss
CONFIGURE_ARGS+=	--disable-dxr3
CONFIGURE_ARGS+=	--disable-qcam
CONFIGURE_ARGS+=	--disable-v4l
CONFIGURE_ARGS+=	--disable-v4l2
CONFIGURE_ARGS+=	--disable-vcd
CONFIGURE_ARGS+=	--disable-vga
CONFIGURE_ARGS+=	--disable-cdrom
CONFIGURE_ARGS+=	--disable-arts
CONFIGURE_ARGS+=	--disable-alsa
CONFIGURE_ARGS+=	--disable-audiofile
CONFIGURE_ARGS+=	--disable-avifile
CONFIGURE_ARGS+=	--disable-cdparanoia
CONFIGURE_ARGS+=	--disable-dvdread
CONFIGURE_ARGS+=	--disable-dvdnav
CONFIGURE_ARGS+=	--disable-ffmpeg
CONFIGURE_ARGS+=	--disable-flac
CONFIGURE_ARGS+=	--disable-gsm
CONFIGURE_ARGS+=	--disable-http
CONFIGURE_ARGS+=	--disable-jack
CONFIGURE_ARGS+=	--disable-ladspa
CONFIGURE_ARGS+=	--disable-lame
CONFIGURE_ARGS+=	--disable-lcs
CONFIGURE_ARGS+=	--disable-libdv
CONFIGURE_ARGS+=	--disable-libfame
CONFIGURE_ARGS+=	--disable-libpng
CONFIGURE_ARGS+=	--disable-mjpegtools
CONFIGURE_ARGS+=	--disable-mpeg2dec
CONFIGURE_ARGS+=	--disable-openquicktime
CONFIGURE_ARGS+=	--disable-raw1394
CONFIGURE_ARGS+=	--disable-rtp
CONFIGURE_ARGS+=	--disable-shout
CONFIGURE_ARGS+=	--disable-shout2
CONFIGURE_ARGS+=	--disable-sidplay
CONFIGURE_ARGS+=	--disable-smoothwave
CONFIGURE_ARGS+=	--disable-swfdec
CONFIGURE_ARGS+=	--disable-tarkin
CONFIGURE_ARGS+=	--disable-tests
CONFIGURE_ARGS+=	--disable-examples
CONFIGURE_ARGS+=	--with-x

GCONF2_SCHEMAS=         gstreamer.schemas

.include "../../audio/esound/buildlink2.mk"
.include "../../audio/liba52/buildlink2.mk"
.include "../../audio/mad/buildlink2.mk"
.include "../../audio/libmikmod/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../graphics/aalib/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/hermes/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../wip/gstreamer/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
