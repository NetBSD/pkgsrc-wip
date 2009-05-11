# $NetBSD: Makefile,v 1.2 2009/05/11 10:46:41 jihbed Exp $
#


DISTNAME=	gst-inspector-0.4
CATEGORIES=	devel
MASTER_SITES=	http://cgit.freedesktop.org/~cymacs/gst-inspector/snapshot/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://renestadler.de/projects/gst-inspector/
COMMENT=	An introspection data viewer for the GStreamer multimedia framework

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		intltool msgfmt gettext
USE_DIRS+=		xdg-1.4

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
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
