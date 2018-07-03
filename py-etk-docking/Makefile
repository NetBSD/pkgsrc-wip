# $NetBSD: Makefile,v 1.5 2014/05/09 07:38:47 thomasklausner Exp $

DISTNAME=	etk.docking-0.2
PKGNAME=	${PYPKGPREFIX}-etk-docking-0.2
CATEGORIES=	x11 python
MASTER_SITES=	https://github.com/downloads/dieterv/etk.docking/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/dieterv/etk.docking/
COMMENT=	PyGTK Docking Widgets
LICENSE=	gnu-lgpl-v3 AND gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-simplegeneric>=0.8:../../wip/py-simplegeneric

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-gtk2, py-gobject

.include "../../devel/py-gobject/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
