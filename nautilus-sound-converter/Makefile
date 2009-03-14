# $NetBSD: Makefile,v 1.1.1.1 2009/03/14 14:58:40 jihbed Exp $
#

DISTNAME=	nautilus-sound-converter-1.0.1
CATEGORIES=	audio gnome
MASTER_SITES=	http://nautilus-sound-converter.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/nautilus-sound-converter/
COMMENT=	Nautilus extension to convert audio files

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	perl intltool
USE_LANGUAGES+=	c c++

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../multimedia/gnome-media/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
