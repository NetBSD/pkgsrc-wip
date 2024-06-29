# $NetBSD$

DISTNAME=	dask-2024.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
GITHUB_PROJECT=	dask
GITHUB_TAG=	${PKGVERSION_NOREV}
MASTER_SITES=	${MASTER_SITE_GITHUB:=dask/}

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/dask/dask/
COMMENT=	Flexible parallel computing library for analytics
LICENSE=	modified-bsd

.include "../../mk/bsd.prefs.mk"

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
TOOL_DEPENDS+=	${PYPKGPREFIX}-versioneer>=0.28:../../devel/py-versioneer

DEPENDS+=	${PYPKGPREFIX}-click>=8.1.3:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-cytoolz-[0-9]*:../../devel/py-cytoolz
DEPENDS+=	${PYPKGPREFIX}-h5py>=2.10:../../devel/py-h5py
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=6.6.0:../../devel/py-importlib-metadata
DEPENDS+=	${PYPKGPREFIX}-mmh3>=2.5.1:../../devel/py-mmh3
DEPENDS+=	${PYPKGPREFIX}-packaging>=20.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-snappy>=0.5.4:../../devel/py-snappy
DEPENDS+=	${PYPKGPREFIX}-toolz>=0.10.0:../../devel/py-toolz
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy-[0-9]*:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-graphviz-[0-9]*:../../graphics/py-graphviz
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3.4.1:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.21:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-pandas>=1.3:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-xarray-[0-9]*:../../math/py-xarray
DEPENDS+=	${PYPKGPREFIX}-scikit-image-[0-9]*:../../math/py-scikit-image
DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-fsspec>=2022.7.1:../../sysutils/py-fsspec
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.10.3:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.3.1:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-apache-arrow>=14.0.1:../../wip/py-apache-arrow
DEPENDS+=	${PYPKGPREFIX}-bokeh>=2.4.2:../../wip/py-bokeh
DEPENDS+=	${PYPKGPREFIX}-cityhash-[0-9]*:../../wip/py-cityhash
DEPENDS+=	${PYPKGPREFIX}-cloudpickle>=1.5.0:../../wip/py-cloudpickle
DEPENDS+=	${PYPKGPREFIX}-dask_expr>=1.1.1:../../wip/py-dask_expr
DEPENDS+=	${PYPKGPREFIX}-distributed>=${GITHUB_TAG}:../../wip/py-distributed
DEPENDS+=	${PYPKGPREFIX}-fastavro>=1.1.0:../../wip/py-fastavro
DEPENDS+=	${PYPKGPREFIX}-partd>=1.2.0:../../wip/py-partd
DEPENDS+=	${PYPKGPREFIX}-tblib>=1.6.0:../../wip/py-tblib
DEPENDS+=	${PYPKGPREFIX}-zict>=2.1.0:../../wip/py-zict

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-rerunfailures-[0-9]*:../../devel/py-test-rerunfailures
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-multipledispatch>=0.6.0:../../devel/py-multipledispatch
TEST_DEPENDS+=	${PYPKGPREFIX}-tables>=3.9:../../math/py-tables
TEST_DEPENDS+=	${PYPKGPREFIX}-numexpr>=2.9.0:../../math/py-numexpr
TEST_DEPENDS+=	${PYPKGPREFIX}-pre-commit-[0-9]*:../../wip/py-pre-commit
# TODO: Get These Working
# TEST_DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.9.5:../../www/py-aiohttp
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
