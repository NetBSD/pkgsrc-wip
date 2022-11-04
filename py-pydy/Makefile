# $NetBSD$

DISTNAME=	pydy-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydy/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pydy.org/
COMMENT=	Python tool kit for multi-body dynamics
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=1.3.3:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-sympy>=1.5.1:../../math/py-sympy
TEST_DEPENDS+=	${PYPKGPREFIX}-nose>=1.3.7:../../devel/py-nose

USE_LANGUAGES=	# none

.include "../../devel/py-cython/buildlink3.mk"
BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.16.5
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
