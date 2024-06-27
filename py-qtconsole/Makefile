# $NetBSD$

DISTNAME=	qtconsole-5.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_PYPI:=q/qtconsole/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://jupyter.org
COMMENT=	Jupyter Qt console
#LICENSE=	BSD # TODO: from setup.py; needs to be adjusted

DEPENDS+=	${PYPKGPREFIX}-traitlets>=5.5.0:../../devel/py-traitlets
DEPENDS+=	${PYPKGPREFIX}-ipython_genutils>=0.2.0:../../devel/py-ipython_genutils
DEPENDS+=	${PYPKGPREFIX}-jupyter_core>=4.10.0:../../devel/py-jupyter_core
DEPENDS+=	${PYPKGPREFIX}-jupyter_client>=4.1:../../devel/py-jupyter_client
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.3.1:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-ipykernel>=4.1:../../devel/py-ipykernel
DEPENDS+=	${PYPKGPREFIX}-QtPy>=2.0.1:../../wip/py-qtpy
DEPENDS+=	${PYPKGPREFIX}-zmq>=17.1:../../net/py-zmq

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
