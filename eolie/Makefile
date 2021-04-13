# $NetBSD$

DISTNAME=	eolie-0.9.99
CATEGORIES=	www python
MASTER_SITES=	https://adishatz.org/eolie/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://wiki.gnome.org/Apps/Eolie
COMMENT=	Simple Web Browser for GNOME
LICENSE=	gnu-gpl-v3

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c
USE_TOOLS+=                     gettext msgfmt perl pkg-config
_TOOLS_USE_PKGSRC.msgfmt=       yes

PYTHON_VERSIONS_INCOMPATIBLE=   27

DEPENDS+=	${PYPKGPREFIX}-sqlite3>=3.7.9:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-gobject3>=3.36.1:../../devel/py-gobject3
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.8.1:../../time/py-dateutil

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk3+=    gtk3+>=3.20
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
