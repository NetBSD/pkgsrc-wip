# $NetBSD: Makefile,v 1.12 2014/05/09 07:38:44 thomasklausner Exp $

DISTNAME=	mirage-0.9.5.2
CATEGORIES=	graphics
MASTER_SITES=	http://download.berlios.de/mirageiv/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	netbsd@guigui2.net
HOMEPAGE=	http://mirageiv.berlios.de/
COMMENT=	Fast and simple image viewer
LICENSE=	gnu-gpl-v3

PY_PATCHPLIST=			yes
PYDISTUTILSPKG=			yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-gtk2

.include "../../devel/GConf/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
