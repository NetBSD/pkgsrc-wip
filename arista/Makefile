# $NetBSD: Makefile,v 1.4 2010/03/16 20:32:56 jihbed Exp $
#

DISTNAME=	arista-0.9.1
CATEGORIES=	multimedia python
MASTER_SITES=	http://programmer-art.org/media/releases/arista-transcoder/

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://programmer-art.org/projects/arista-transcoder
COMMENT=	Tools multimedia transcoder for GNOME
LICENSE=	gnu-lgpl-v2

DEPENDS+=	gst-ffmpeg-[0-9]*:../../multimedia/gst-plugins0.10-ffmpeg
DEPENDS+=	gst-plugins0.10-x264-[0-9]*:../../multimedia/gst-plugins0.10-x264

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=	intltool msgfmt
USE_LANGUAGES=		# none

PYDISTUTILSPKG=		yes

.include "../../devel/py-gobject/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-bad/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-good/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-ugly/buildlink3.mk"
BUILDLINK_API_DEPENDS.gst-python+=	${PYPKGPREFIX}-gstreamer0.10>=0.10.5
.include "../../multimedia/py-gstreamer0.10/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../textproc/py-elementtree/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
BUILDLINK_ABI_DEPENDS.pygtk2+=	${PYPKGPREFIX}-gtk2>=2.8.5nb1
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
