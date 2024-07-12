# $NetBSD$

DISTNAME=	dask_expr-1.1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dask_expr/}

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://pypi.org/project/dask_expr/
COMMENT=	Query Optimizer for the Dask Dataframes
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27 38
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
TOOL_DEPENDS+=	${PYPKGPREFIX}-versioneer>=0.28:../../devel/py-versioneer

DEPENDS+=	${PYPKGPREFIX}-pandas>=2:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-apache-arrow>=7.0.0:../../wip/py-apache-arrow
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

#do-test:
#	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m pytest -s
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
