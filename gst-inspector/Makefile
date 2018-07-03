# $NetBSD: Makefile,v 1.12 2014/05/09 07:38:43 thomasklausner Exp $

DISTNAME=	gst-inspector-0.4
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://cgit.freedesktop.org/~cymacs/gst-inspector/snapshot/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://renestadler.de/projects/gst-inspector/
COMMENT=	Multimedia system plugin introspection for the GStreamer framework
LICENSE=	gnu-gpl-v3

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		intltool msgfmt gettext

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-gtk2, py-gstreamer0.10, py-gobject

.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/py-gstreamer0.10/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-gtk2/buildlink3.mk"

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
