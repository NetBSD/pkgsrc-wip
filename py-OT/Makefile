# $NetBSD$

DISTNAME=	POT-0.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/POT/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pythonot.github.io/
COMMENT=	Python Optimal Transport Library
LICENSE=	mit

USE_LANGUAGES=	c c++

DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3.3.4:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.6.0:../../math/py-scipy

BUILDLINK_API_DEPENDS.py-cython+=       ${PYPKGPREFIX}-cython>=0.12.1
.include "../../devel/py-cython/buildlink3.mk"
BUILDLINK_API_DEPENDS.py-numpy+=        ${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
