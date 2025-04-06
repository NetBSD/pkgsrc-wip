# $NetBSD$

DISTNAME=	fastcluster-1.2.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fastcluster/}

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	http://danifold.net/fastcluster.html
COMMENT=	Fast hierarchical clustering routines for R and Python
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	27

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=68.2:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
TEST_DEPENDS+=	${PYPKGPREFIX}-scipy>=1.6:../../math/py-scipy

# Tests Requires installing the package
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} tests/test.py
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} tests/vectortest.py
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} tests/nantest.py

.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
