# $NetBSD$

DISTNAME=	bokeh-2.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bokeh/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/bokeh/bokeh
COMMENT=	Statistical and novel interactive HTML plots for Python
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-packaging>=20.4:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-Pillow>=6.2.2:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.11:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.4.0:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-tornado-[0-9]*:../../www/py-tornado

BUILDLINK_API_DEPENDS.py-numpy+=        ${PYPKGPREFIX}-numpy>=1.11
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
