# $NetBSD: Makefile,v 1.4 2005/04/11 21:13:36 tvierling Exp $
#

DISTNAME=		kino-0.7.1
CATEGORIES=		multimedia
MASTER_SITES=		http://kino.schirmacher.de/filemanager/download/31/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://kino.schirmacher.de/
COMMENT=		Non-linear editor for Digital Video data

USE_X11=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

# Use FFMPEG libavcodec for DV video decoding instead of libdv.  
# XXX maybe should be an option
#CONFIGURE_ARGS+=	--with-avcodec
#.include "../../multimedia/ffmpeg/buildlink3.mk"

.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/GConf2/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
# maybe configure should not use old glib?
.include "../../devel/glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../multimedia/libdv/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.include "../../wip/libavc1394/buildlink3.mk"
.include "../../wip/libraw1394/buildlink3.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
