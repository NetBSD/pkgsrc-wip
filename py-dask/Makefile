# $NetBSD$

GITHUB_TAG=	2023.7.0
DISTNAME=	dask-${GITHUB_TAG}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
GITHUB_PROJECT=	dask
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_GITHUB:=dask/}


MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/dask/dask/
COMMENT=	Flexible parallel computing library for analytics
LICENSE=	modified-bsd

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

PYTHON_VERSIONS_INCOMPATIBLE=	27 37 38

TOOL_DEPENDS+=       ${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
TOOL_DEPENDS+=       ${PYPKGPREFIX}-versioneer>=0.28:../../devel/py-versioneer

DEPENDS+=	${PYPKGPREFIX}-toolz>=0.8.2:../../devel/py-toolz
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.18:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-pandas>=1.0:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-partd>=0.3.10:../../wip/py-partd
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.3.1:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-distributed>=2023.6.0:../../wip/py-distributed
DEPENDS+=	${PYPKGPREFIX}-cloudpickle>=1.1.1:../../wip/py-cloudpickle
DEPENDS+=	${PYPKGPREFIX}-fsspec>=2022.7.1:../../sysutils/py-fsspec
DEPENDS+=	${PYPKGPREFIX}-zict>=2.1.0:../../wip/py-zict
DEPENDS+=	${PYPKGPREFIX}-packaging>=20.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-rerunfailures-[0-9]*:../../devel/py-test-rerunfailures
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-multipledispatch>=0.6.0*:../../devel/py-multipledispatch
TEST_DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=6.6.0*:../../devel/py-importlib-metadata
TEST_DEPENDS+=	${PYPKGPREFIX}-pre-commit-[0-9]*:../../wip/py-pre-commit
# TEST_DEPENDS+=	${PYPKGPREFIX}-s3fs>=2022*:../../wip/py-s3fs
# TEST_DEPENDS+=	${PYPKGPREFIX}-sparse>=0.11.2:../../wip/py-sparse

# The setup.py has integration with pytest-runner, but throws odd errors
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m pytest -s

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} dask dask-${PYVERSSUFFIX}

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
