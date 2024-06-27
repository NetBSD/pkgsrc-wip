# $NetBSD$

DISTNAME=	spyder-kernels-2.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/spyder-kernels/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/spyder-ide/spyder-kernels
COMMENT=	Jupyter kernels for Spyder's console
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-decorator-[0-9]*:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-cloudpickle>=2.2.0:../../wip/py-cloudpickle
DEPENDS+=	${PYPKGPREFIX}-ipykernel>=6.16.1:../../devel/py-ipykernel
DEPENDS+=	${PYPKGPREFIX}-ipython>=7.31.1:../../devel/py-ipython
DEPENDS+=	${PYPKGPREFIX}-jupyter_client>=:../../devel/py-jupyter_client
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-zmq>=:../../net/py-zmq
DEPENDS+=	${PYPKGPREFIX}-wurlitzer>=1.0.3:../../wip/py-wurlitzer

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
