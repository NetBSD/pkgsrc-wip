# $NetBSD: Makefile,v 1.18 2014/08/11 23:10:13 thomasklausner Exp $

# XXX You must update MASTER_SITES download number when updating
# XXX or you will download old file with new filename.
DISTNAME=		kino-0.7.5
PKGREVISION=		6
CATEGORIES=		multimedia
MASTER_SITES=		http://kino.schirmacher.de/filemanager/download/42/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.kinodv.org/
COMMENT=		Non-linear editor for Digital Video data


USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

# maybe need to do CONF_DIRS for this? Is this important?
CONFIGURE_ARGS+=	--with-hotplug-script-dir=${PREFIX}/share/examples/kino/hotplug/usb
# or should the following be used to not use default PREFIX/lib/hotplug/kino ?
#CONFIGURE_ARGS+=	--with-hotplug-usermap-dir=${PREFIX}/libdata/hotplug/kino

# Use FFMPEG libavcodec for DV video decoding instead of libdv.
# XXX maybe should be an option
#CONFIGURE_ARGS+=	--with-avcodec
#.include "../../multimedia/ffmpeg1/buildlink3.mk"


.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
## maybe configure should not use old glib?
# objdump of kino shows NEEDED of both libglib-2.0.so.0 and libglib.so.13
.include "../../devel/glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
#.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../multimedia/libdv/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/libavc1394/buildlink3.mk"
.include "../../wip/libraw1394/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
