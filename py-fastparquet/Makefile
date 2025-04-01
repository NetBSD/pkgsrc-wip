# $NetBSD$

# Prefer pulling from github instead of pypi
# so that we can run tests
GITHUB_TAG=	2024.5.0
GITHUB_PROJECT=	fastparquet
DISTNAME=	fastparquet-${GITHUB_TAG}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=dask/}


MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/dask/fastparquet
COMMENT=	Python implementation of the parquet format
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++
PYTHON_VERSIONS_INCOMPATIBLE=	27 38
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
TOOL_DEPENDS+=	${PYPKGPREFIX}-packaging>=0:../../devel/py-packaging
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=4.1.2:../../devel/py-setuptools_scm

DEPENDS+=	${PYPKGPREFIX}-numpy>=1.20:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-pandas>=1.5.0:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-cramjam>=2.3.0:../../archivers/py-cramjam
DEPENDS+=	${PYPKGPREFIX}-fsspec>=2022.3.0:../../sysutils/py-fsspec

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
TEST_DEPENDS+=	${PYPKGPREFIX}-ujson-[0-9]*:../../textproc/py-ujson
TEST_DEPENDS+=	${PYPKGPREFIX}-rapidjson-[0-9]*:../../textproc/py-rapidjson
TEST_DEPENDS+=	${PYPKGPREFIX}-orjson-[0-9]*:../../textproc/py-orjson

post-extract:
	${CP} ${FILESDIR}/PKG-INFO ${WRKSRC}

# The setup.py has integration with pytest-runner, but throws odd errors
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} setup.py build_ext -i
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m pytest

.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
