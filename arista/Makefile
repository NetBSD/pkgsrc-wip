# $NetBSD: Makefile,v 1.9 2014/05/09 07:38:42 thomasklausner Exp $

DISTNAME=	arista-0.9.1
PKGREVISION=	1
CATEGORIES=	multimedia python
MASTER_SITES=	http://programmer-art.org/media/releases/arista-transcoder/

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://programmer-art.org/projects/arista-transcoder
COMMENT=	Tools multimedia transcoder for GNOME
LICENSE=	gnu-lgpl-v2

DEPENDS+=	gst-ffmpeg-[0-9]*:../../multimedia/gst-plugins0.10-ffmpeg
DEPENDS+=	gst-plugins0.10-x264-[0-9]*:../../multimedia/gst-plugins0.10-x264

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=	intltool msgfmt
USE_LANGUAGES=		# none

PYDISTUTILSPKG=		yes
PYTHON_VERSIONED_DEPENDENCIES=	cairo
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # py-ORBit via py-gnome2, py-gtk2, py-gstreamer0.10, py-gobject, py-elementtree

.include "../../devel/py-gobject/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
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
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
