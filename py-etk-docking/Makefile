# $NetBSD: Makefile,v 1.1 2012/10/03 22:30:36 jihbed Exp $
#

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

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

.include "../../devel/py-gobject/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
