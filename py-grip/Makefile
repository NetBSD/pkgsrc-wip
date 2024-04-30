# $NetBSD$

DISTNAME=	grip-4.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/grip/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/joeyespo/grip/
COMMENT=	Render local readme files before sending off to GitHub
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-docopt>=0.4.0:../../devel/py-docopt
DEPENDS+=	${PYPKGPREFIX}-flask>=0.10.1:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-markdown>=2.5.1:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-path-and-address>=2.0.1:../../wip/py-path-and-address
DEPENDS+=	${PYPKGPREFIX}-pygments>=1.6:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-requests>=2.4.1:../../devel/py-requests

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
