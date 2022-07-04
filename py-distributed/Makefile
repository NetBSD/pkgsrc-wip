# $NetBSD$

DISTNAME=	distributed-2022.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel net
MASTER_SITES=	${MASTER_SITE_PYPI:=d/distributed/}


MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/dask/distributed/
COMMENT=	Distributed is the parallel scheduler for dask
LICENSE=	modified-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-dask-[0-9]*:../../wip/py-dask
DEPENDS+=	${PYPKGPREFIX}-sortedcontainers>=2.0.1:../../devel/py-sortedcontainers
DEPENDS+=	${PYPKGPREFIX}-cloudpickle>=1.5.0:../../wip/py-cloudpickle
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-msgpack-[0-9]*:../../devel/py-msgpack
DEPENDS+=	${PYPKGPREFIX}-psutil>=5.0:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-toolz>=0.8.2:../../devel/py-toolz
DEPENDS+=	${PYPKGPREFIX}-tornado>=6.0.3:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-tblib>=1.7.0:../../wip/py-tblib

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
