# $NetBSD$

DISTNAME=	bidict-0.21.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python devel
MASTER_SITES=	https://files.pythonhosted.org/packages/bd/7c/83fbbc8568be511bc48704b97ef58f67ff2ab85ec4fcd1dad12cd2323c32/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://bidict.readthedocs.io
COMMENT=	The bidirectional mapping library for Python
LICENSE=	mpl-2.0

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=4.1.2:../../devel/py-setuptools_scm
BUILD_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=4.57.1:../../devel/py-hypothesis
BUILD_DEPENDS+= ${PYPKGPREFIX}-test>=5.3.5:../../devel/py-test
BUILD_DEPENDS+= ${PYPKGPREFIX}-test-benchmark>=3.2.3:../../devel/py-test-benchmark
BUILD_DEPENDS+= ${PYPKGPREFIX}-sortedcollections>=1.2.1:../../wip/py-sortedcollections
BUILD_DEPENDS+= ${PYPKGPREFIX}-sortedcontainers>=2.2.2:../../devel/py-sortedcontainers
BUILD_DEPENDS+= ${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
BUILD_DEPENDS+= ${PYPKGPREFIX}-sphinx-autodoc-typehints>=1.10.3:../../textproc/py-sphinx-autodoc-typehints
BUILD_DEPENDS+=	${PYPKGPREFIX}-coverage>=5.2.1:../../devel/py-coverage
BUILD_DEPENDS+= ${PYPKGPREFIX}-test-cov>=2.10.1:../../devel/py-test-cov
#BUILD_DEPENDS+= ${PYPKGPREFIX}-pre-commit>=2.7.1:../../wip/py-pre-commit
BUILD_DEPENDS+= ${PYPKGPREFIX}-tox>=3.12.1:../../devel/py-tox

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} run_tests.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
