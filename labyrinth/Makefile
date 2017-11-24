# $NetBSD: Makefile,v 1.11 2014/05/09 07:38:43 thomasklausner Exp $

DISTNAME=	labyrinth_0.4.1
PKGNAME=	labyrinth-0.4.1
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	http://labyrinth.googlecode.com/files/

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	https://www.gnome.org/~dscorgie/labyrinth.html
COMMENT=	Labyrinth is a lightweight mind-mapping tool for GNOME

DEPENDS+=	${PYPKGPREFIX}-cairo-[0-9]*:../../graphics/py-cairo

WRKSRC=		${WRKDIR}/labyrinth-0.4.0
GNU_CONFIGURE=	yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gmake
USE_LANGUAGES=	c c++

PY_PATCHPLIST=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-ORBit via py-gnome2, py-gobject

.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
