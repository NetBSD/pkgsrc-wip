# $NetBSD: Makefile,v 1.1 2015/01/04 08:58:19 obache Exp $

DISTNAME=	mozo-1.8.0
CATEGORIES=	x11
MASTER_SITES=	http://pub.mate-desktop.org/releases/1.8/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.mate-desktop.org/
COMMENT=	Menu editor for MATE
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-gobject>=2.15.1:../../devel/py-gobject
DEPENDS+=	${PYPKGPREFIX}-gtk2>=2.13.0:../../x11/py-gtk2

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake intltool msgfmt pkg-config

PY_PATCHPLIST=	yes

.include "../../wip/mate-menus/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
