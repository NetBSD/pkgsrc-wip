# $NetBSD: Makefile,v 1.18 2022/04/10 00:57:15 gutteridge Exp $

DISTNAME=	scikit-learn-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scikit-learn/}

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://scikit-learn.org/
COMMENT=	Machine learning algorithms for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-joblib>=0.11:../../devel/py-joblib
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.17.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-threadpoolctl>=3.1.0:../../wip/py-threadpoolctl

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	c c++ fortran
USE_TOOLS+=	gmake

PYTHON_VERSIONS_INCOMPATIBLE=	27 37 # py-scipy

TEST_ENV+=PYTHON=python${PYVERSSUFFIX}
TEST_ENV+=PYTEST=py.test-${PYVERSSUFFIX}
TEST_ENV+=PYTHONPATH=.
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} gmake test

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.11.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
