# $NetBSD$

GITHUB_TAG=	2024.4.2
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

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
TOOL_DEPENDS+=	${PYPKGPREFIX}-versioneer>=0.28:../../devel/py-versioneer

DEPENDS+=	${PYPKGPREFIX}-cloudpickle>=1.5.0:../../wip/py-cloudpickle
DEPENDS+=	${PYPKGPREFIX}-click>=8.1.3:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-fsspec>=2022.7.1:../../sysutils/py-fsspec
DEPENDS+=	${PYPKGPREFIX}-packaging>=20.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-partd>=1.2.0:../../wip/py-partd
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.3.1:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-toolz>=0.10.0:../../devel/py-toolz
DEPENDS+=	${PYPKGPREFIX}-distributed>=${GITHUB_TAG}:../../wip/py-distributed
# Optional Dependencies
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.21:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.10.3:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-pandas>=1.3:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-zict>=2.1.0:../../wip/py-zict

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-rerunfailures-[0-9]*:../../devel/py-test-rerunfailures
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-multipledispatch>=0.6.0:../../devel/py-multipledispatch
TEST_DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=6.6.0:../../devel/py-importlib-metadata
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
