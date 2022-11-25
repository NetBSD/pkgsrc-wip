# $NetBSD$

DISTNAME=	neumann-0.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/neumann/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/dewloosh/Neumann
COMMENT=	Python Library for Applied Mathematics in Physical Sciences
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-numba>=0.55.2:../../math/py-numba
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.9.3:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-awkward>=1.10.2:../../wip/py-awkward
DEPENDS+=	${PYPKGPREFIX}-sympy>=1.9:../../math/py-sympy
DEPENDS+=	${PYPKGPREFIX}-dewloosh.core>=1.0.12:../../wip/py-dewloosh.core

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.8
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
