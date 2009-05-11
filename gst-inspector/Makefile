# $NetBSD: Makefile,v 1.3 2009/05/11 15:49:00 jihbed Exp $
#


DISTNAME=	gst-inspector-0.4
CATEGORIES=	devel python
MASTER_SITES=	http://cgit.freedesktop.org/~cymacs/gst-inspector/snapshot/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://renestadler.de/projects/gst-inspector/
COMMENT=	Multimedia system plugin introspection for the GStreamer framework

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		intltool msgfmt gettext
USE_DIRS+=		xdg-1.4 gnome2-1.6

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

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
