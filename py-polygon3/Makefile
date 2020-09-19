# $NetBSD$

DISTNAME=	Polygon3-3.0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	graphics python
MASTER_SITES=	https://files.pythonhosted.org/packages/73/a0/d07a4f3e80ed7020a33f3111db217f54ac44a485ff45da3c21ce49f65041/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.j-raedler.de/projects/polygon
COMMENT=	Python-3 package that handles polygonal shapes in 2D
LICENSE=	gnu-lgpl-v2

DEPENDS+=	${PYPKGPREFIX}-reportlab>=3.5.42:../../print/py-reportlab

PYTHON_VERSIONS_INCOMPATIBLE=	27

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=        ${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
