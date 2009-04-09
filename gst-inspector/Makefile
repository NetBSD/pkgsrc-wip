# $NetBSD: Makefile,v 1.1.1.1 2009/04/09 16:23:22 jihbed Exp $
#


DISTNAME=	gst-inspector-0.4
CATEGORIES=	devel
MASTER_SITES=	http://cgit.freedesktop.org/~cymacs/gst-inspector/snapshot/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://renestadler.de/projects/gst-inspector/
COMMENT=	Multimedia system plugin introspection

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		intltool
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
.include "../../x11/py-gtk2/buildlink3.mk"

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
