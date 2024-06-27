# $NetBSD$

DISTNAME=	altair-5.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/altair/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://altair-viz.github.io/
COMMENT=	Altair: A declarative statistical visualization library for Python
LICENSE=	2-clause-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

TOOL_DEPENDS+=		${PYPKGPREFIX}-black>=20.8:../../textproc/py-black
TOOL_DEPENDS+=		${PYPKGPREFIX}-docutils>=0.16:../../textproc/py-docutils
TOOL_DEPENDS+=		${PYPKGPREFIX}-hatchling>=1.24.2:../../devel/py-hatchling
TOOL_DEPENDS+=		${PYPKGPREFIX}-ipython>=0:../../devel/py-ipython
TOOL_DEPENDS+=		${PYPKGPREFIX}-flake8>=3.3.0:../../devel/py-flake8
TOOL_DEPENDS+=		${PYPKGPREFIX}-typing-extensions>=4.0.1:../../devel/py-typing-extensions
TOOL_DEPENDS+=		${PYPKGPREFIX}-sphinx>=2.4.4:../../textproc/py-sphinx
TOOL_DEPENDS+=		${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
TOOL_DEPENDS+=		${PYPKGPREFIX}-recommonmark>=0.6.0:../../wip/py-recommonmark
DEPENDS+=		${PYPKGPREFIX}-entrypoints>=0.3:../../devel/py-entrypoints
DEPENDS+=		${PYPKGPREFIX}-jinja2>=2.11.2:../../textproc/py-jinja2
DEPENDS+=		${PYPKGPREFIX}-jsonschema>=3.2.0:../../textproc/py-jsonschema
DEPENDS+=		${PYPKGPREFIX}-pandas>=0.18:../../math/py-pandas
DEPENDS+=		${PYPKGPREFIX}-toolz>=0.10.0:../../devel/py-toolz
DEPENDS+=		${PYPKGPREFIX}-apache-arrow>=11.0:../../wip/py-apache-arrow
DEPENDS+=		${PYPKGPREFIX}-anywidget>=0.9.0:../../wip/py-anywidget
TEST_DEPENDS+=		${PYPKGPREFIX}-test>=4.3.1:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-vega_datasets>=0.9.0:../../wip/py-vega_datasets

USE_LANGUAGES=	# none
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m pytest -s --doctest-modules

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
