# $NetBSD$

DISTNAME=	pyqtgraph-0.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	graphics python
MASTER_SITES=	https://files.pythonhosted.org/packages/d3/89/be1585cd56edb8e47db95d4844ec5f766ffbd391a561495f8953fe102d6e/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.pyqtgraph.org/
COMMENT=	Scientific Graphics and GUI Library for Python
LICENSE=	mit

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
BUILDLINK_API_DEPENDS.py-qt5+=	${PYPKGPREFIX}-qt5>=5.2.1
.include "../../x11/py-qt5/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
