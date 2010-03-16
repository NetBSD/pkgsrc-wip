# $NetBSD: Makefile,v 1.4 2010/03/16 19:56:40 jihbed Exp $
#

DISTNAME=	labyrinth_0.4.1
PKGNAME=	labyrinth-0.4.1
CATEGORIES=	graphics python
MASTER_SITES=	http://labyrinth.googlecode.com/files/

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://www.gnome.org/~dscorgie/labyrinth.html
COMMENT=	Labyrinth is a lightweight mind-mapping tool for GNOME

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/labyrinth-0.4.0
GNU_CONFIGURE=	yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gmake
USE_LANGUAGES=	c c++

PYTHON_VERSIONS_ACCEPTED=   26 25
PY_PATCHPLIST=		yes

.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
