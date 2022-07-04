# $NetBSD$

DISTNAME=	threadpoolctl-3.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=t/threadpoolctl/}

MAINTAINER=	matthewd@fastmail.us
COMMENT=	Python helpers to limit the number of threads of datascience tools
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.7.1:../../devel/py-flit_core
TEST_DEPENDS+=	${PYPKGPREFIX}-scipy>=1.8.1:../../math/py-scipy
TEST_DEPENDS+=	${PYPKGPREFIX}-cython>=0.29.30:../../devel/py-cython

USE_LANGUAGES+= c c++

do-test:
	# From continous_integration/build_test_ext.sh
	cd ${WRKSRC}/tests/_openmp_test_helper && ${SETENV} ${TEST_ENV} ${PYTHONBIN} setup_inner.py build_ext -i
	cd ${WRKSRC}/tests/_openmp_test_helper && ${SETENV} ${TEST_ENV} ${PYTHONBIN} setup_outer.py build_ext -i
	cd ${WRKSRC}/tests/_openmp_test_helper && ${SETENV} ${TEST_ENV} ${PYTHONBIN} setup_nested_prange_blas.py build_ext -i
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m pytest -s -v

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
