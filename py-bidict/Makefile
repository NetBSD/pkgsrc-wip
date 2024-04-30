# $NetBSD$

DISTNAME=	bidict-0.21.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python devel
MASTER_SITES=	https://files.pythonhosted.org/packages/bd/7c/83fbbc8568be511bc48704b97ef58f67ff2ab85ec4fcd1dad12cd2323c32/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://bidict.readthedocs.io
COMMENT=	The bidirectional mapping library for Python
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=4.1.2:../../devel/py-setuptools_scm
TOOL_DEPENDS+= ${PYPKGPREFIX}-test>=5.3.5:../../devel/py-test
TOOL_DEPENDS+= ${PYPKGPREFIX}-test-benchmark>=3.2.3:../../devel/py-test-benchmark
TOOL_DEPENDS+= ${PYPKGPREFIX}-sortedcollections>=1.2.1:../../wip/py-sortedcollections
TOOL_DEPENDS+= ${PYPKGPREFIX}-sortedcontainers>=2.2.2:../../devel/py-sortedcontainers
TOOL_DEPENDS+= ${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
TOOL_DEPENDS+= ${PYPKGPREFIX}-sphinx-autodoc-typehints>=1.10.3:../../textproc/py-sphinx-autodoc-typehints
TOOL_DEPENDS+=	${PYPKGPREFIX}-coverage>=5.2.1:../../devel/py-coverage
TOOL_DEPENDS+= ${PYPKGPREFIX}-test-cov>=2.10.1:../../devel/py-test-cov
TOOL_DEPENDS+= ${PYPKGPREFIX}-pre-commit>=2.7.1:../../wip/py-pre-commit
TOOL_DEPENDS+= ${PYPKGPREFIX}-tox>=3.12.1:../../devel/py-tox
TEST_DEPENDS+= ${PYPKGPREFIX}-hypothesis>=0:../../devel/py-hypothesis

PYTHON_VERSIONS_INCOMPATIBLE=	27
USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} run_tests.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
