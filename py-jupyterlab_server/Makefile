# $NetBSD$

DISTNAME=	jupyterlab_server-2.15.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jupyterlab_server/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/jupyterlab_server/
COMMENT=	JupyterLab Server sits between JupyterLab and Jupyter Server
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-hatchling>0.25:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-babel>0:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=3.6:../../devel/py-importlib-metadata
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.0.3:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-json5>0:../../wip/py-json5
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=3.0.1:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-jupyter_server>=1.16:../../wip/py-jupyter_server
DEPENDS+=	${PYPKGPREFIX}-packaging>=21.3:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-requests>0:../../devel/py-requests

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
