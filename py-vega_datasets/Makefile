# $NetBSD$

DISTNAME=	vega_datasets-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/vega_datasets/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/altair-viz/vega_datasets
COMMENT=	Python package for offline access to Vega datasets
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	27 38
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=70.0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-pandas>=1.5.0:../../math/py-pandas
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.2.1:../../devel/py-test

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m pytest -s --doctest-modules vega_datasets

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
