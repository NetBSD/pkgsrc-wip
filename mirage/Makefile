# $NetBSD: Makefile,v 1.5 2010/06/13 22:47:11 thomasklausner Exp $
#

DISTNAME=			mirage-0.9.3
PKGREVISION=			1
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

.include "../../devel/GConf/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
