# $NetBSD: Makefile,v 1.6 2010/07/17 13:08:34 jihbed Exp $
#

DISTNAME=	nautilus-sound-converter-1.0.5
CATEGORIES=	wip
MASTER_SITES=	http://nautilus-sound-converter.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://code.google.com/p/nautilus-sound-converter/
COMMENT=	Nautilus extension to convert audio files

#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	perl intltool msgfmt gmake
USE_LANGUAGES+=	c c++

GCONF_SCHEMAS+=	data/nautilus-sound-converter.schemas

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
