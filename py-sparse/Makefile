# $NetBSD$

DISTNAME=	sparse-0.15.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sparse/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://sparse.pydata.org/
COMMENT=	Sparse multi-dimensional arrays for the PyData ecosystem
LICENSE=	2-clause-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27 38 312

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-numba>=0.51.2:../../math/py-numba
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.21:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.5.2:../../math/py-scipy

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.17

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../math/py-scipy
TEST_DEPENDS+=	${PYPKGPREFIX}-dask-[0-9]*:../../wip/py-dask
TEST_DEPENDS+=	${PYPKGPREFIX}-pre-commit-[0-9]*:../../wip/py-pre-commit

.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
