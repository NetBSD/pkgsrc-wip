# $NetBSD: Makefile,v 1.3 2009/03/21 12:58:02 jihbed Exp $
#

DISTNAME=			mirage-0.9.3
CATEGORIES=			graphics
MASTER_SITES=			http://download.berlios.de/mirageiv/
EXTRACT_SUFX=			.tar.bz2

MAINTAINER=			netbsd@guigui2.net
HOMEPAGE=			http://mirageiv.berlios.de/
COMMENT=			Fast and simple image viewer

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED=	25 24
PY_PATCHPLIST=			yes
PYDISTUTILSPKG=			yes
USE_DIRS+=			xdg-1.4

.include "../../devel/GConf/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
