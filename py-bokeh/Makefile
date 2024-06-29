# $NetBSD$

DISTNAME=	bokeh-3.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bokeh/}

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/bokeh/bokeh
COMMENT=	Statistical and novel interactive HTML plots for Python
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

DEPENDS+=	${PYPKGPREFIX}-packaging>=16.8:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-Pillow>=7.1.0:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-contourpy>=1.2:../../graphics/py-contourpy
DEPENDS+=	${PYPKGPREFIX}-pandas>=1.2:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.9:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.4.0:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-tornado>=6.2:../../www/py-tornado
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky-[0-9]*:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-selenium-[0-9]*:../../www/py-selenium
TEST_DEPENDS+=	geckodriver-[0-9]*:../../www/geckodriver
TEST_DEPENDS+=	nodejs-[0-9]*:../../lang/nodejs

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m pytest -s
post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} bokeh bokeh-${PYVERSSUFFIX}

BUILDLINK_API_DEPENDS.py-numpy+=        ${PYPKGPREFIX}-numpy>=1.16
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
