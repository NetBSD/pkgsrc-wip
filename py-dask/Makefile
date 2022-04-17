# $NetBSD$

GITHUB_TAG=	2022.04.0
DISTNAME=	dask-${GITHUB_TAG}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
GITHUB_PROJECT=	dask
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_GITHUB:=dask/}


MAINTAINER=	matthewda@fastmail.us
HOMEPAGE=	https://github.com/dask/dask/
COMMENT=	Flexible parallel computing library for analytics
LICENSE=	modified-bsd

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

DEPENDS+=	${PYPKGPREFIX}-toolz>=0.8.2:../../devel/py-toolz
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.18:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-pandas>=1.0:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-partd>=0.3.10:../../wip/py-partd
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.3.1:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-distributed>=2022.2.1:../../wip/py-distributed
DEPENDS+=	${PYPKGPREFIX}-cloudpickle>=1.1.1:../../wip/py-cloudpickle
DEPENDS+=	${PYPKGPREFIX}-fsspec>=0.6.0:../../wip/py-fsspec
DEPENDS+=	${PYPKGPREFIX}-zict>=2.1.0:../../wip/py-zict
DEPENDS+=	${PYPKGPREFIX}-packaging>=20.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-rerunfailures-[0-9]*:../../devel/py-test-rerunfailures
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-pre-commit-[0-9]*:../../wip/py-pre-commit

# The setup.py has integration with pytest-runner, but throws odd errors
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m pytest -s

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
