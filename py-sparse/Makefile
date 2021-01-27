# $NetBSD$

DISTNAME=	sparse-0.11.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sparse/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://sparse.pydata.org/
COMMENT=	Sparse multi-dimensional arrays for the PyData ecosystem
LICENSE=	2-clause-bsd

PYTHON_VERSIONS_INCOMPATIBLE+=	36

DEPENDS+=		${PYPKGPREFIX}-numba>=0.51.2:../../math/py-numba
DEPENDS+=               ${PYPKGPREFIX}-scipy>=1.5.2:../../math/py-scipy

BUILDLINK_API_DEPENDS.pynumpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
