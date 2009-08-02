# $NetBSD: Makefile,v 1.3 2009/08/02 23:03:11 jihbed Exp $
#

DISTNAME=	nautilus-sound-converter-1.0.2
CATEGORIES=	audio gnome sysutils
MASTER_SITES=	http://nautilus-sound-converter.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/nautilus-sound-converter/
COMMENT=	Nautilus extension to convert audio files

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	perl intltool msgfmt
USE_LANGUAGES+=	c c++

BUILDLINK_API_DEPENDS.nautilus+=	nautilus>=2.12.1nb1

.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../multimedia/gnome-media/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-good/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
