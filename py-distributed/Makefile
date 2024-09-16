# $NetBSD$

DISTNAME=	distributed-2024.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel net
GITHUB_PROJECT=	distributed
MASTER_SITES=	${MASTER_SITE_GITHUB:=dask/}


MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/dask/distributed/
COMMENT=	Distributed is the parallel scheduler for dask
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
TOOL_DEPENDS+=	${PYPKGPREFIX}-versioneer>=0.28:../../devel/py-versioneer

DEPENDS+=	${PYPKGPREFIX}-click>=8.1.3:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-cloudpickle>=2.2.0:../../converters/py-cloudpickle
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.10.3:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-locket>=1.0.0:../../wip/py-locket
DEPENDS+=	${PYPKGPREFIX}-msgpack>=1.0.0:../../devel/py-msgpack
DEPENDS+=	${PYPKGPREFIX}-packaging>=20.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-psutil>=5.7.2:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.3.1:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-sortedcontainers>=2.0.5:../../devel/py-sortedcontainers
DEPENDS+=	${PYPKGPREFIX}-tblib>=1.6.0:../../wip/py-tblib
DEPENDS+=	${PYPKGPREFIX}-toolz>=0.10.0:../../devel/py-toolz
DEPENDS+=	${PYPKGPREFIX}-tornado>=6.0.4:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.24.3:../../www/py-urllib3
DEPENDS+=	${PYPKGPREFIX}-zict>=3.0.0:../../wip/py-zict

TEST_DEPENDS+=	${PYPKGPREFIX}-lz4>=3.1.10:../../archivers/py-lz4
TEST_DEPENDS+=	${PYPKGPREFIX}-zstandard>=0.18.0:../../archivers/py-zstandard
TEST_DEPENDS+=	${PYPKGPREFIX}-requests>=2.28.1:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-dask-2022.11.0{,nb*}:../../wip/py-dask
TEST_DEPENDS+=	${PYPKGPREFIX}-ipywidgets>=7.7.0:../../www/py-ipywidgets

USE_LANGUAGES=	# none
post-install:
	cd ${DESTDIR}${PREFIX} && \
	${MV} bin/dask-scheduler bin/dask-scheduler-${PYVERSSUFFIX} && \
	${MV} bin/dask-ssh bin/dask-ssh-${PYVERSSUFFIX} && \
	${MV} bin/dask-worker bin/dask-worker-${PYVERSSUFFIX} || ${TRUE}


do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m pytest -s

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
