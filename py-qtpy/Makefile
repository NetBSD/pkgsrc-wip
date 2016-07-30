# $NetBSD$

DISTNAME=	QtPy-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_PYPI:=q/QtPy/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/spyder-ide/qtpy
COMMENT=	Provides an abstraction layer on top of the various Qt bindings
LICENSE=	mit

WRKSRC=		${WRKDIR}/QtPy-1.1.1

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../x11/py-qt4/buildlink3.mk"
#.include "../../x11/py-qt5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
