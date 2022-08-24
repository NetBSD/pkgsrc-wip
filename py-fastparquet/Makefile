# $NetBSD$

# Prefer pulling from github instead of pypi
# so that we can run tests
DISTNAME=	fastparquet-0.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
GITHUB_PROJECT=	fastparquet
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=dask/}

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/dask/fastparquet
COMMENT=	Python implementation of the parquet format,
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++

DEPENDS+=	${PYPKGPREFIX}-numpy>=1.18:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-pandas>=1.1.0:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-cramjam>=2.3.0:../../wip/py-cramjam
DEPENDS+=	${PYPKGPREFIX}-fsspec>=2022.3.0:../../wip/py-fsspec

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner


.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
