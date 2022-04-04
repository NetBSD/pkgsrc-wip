# $NetBSD$

DISTNAME=	zict-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zict/}


MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/dask/zict/
COMMENT=	Mutable Mapping Interfaces
LICENSE=	modified-bsd


DEPENDS+=	${PYPKGPREFIX}-HeapDict-[0-9]*:../../wip/py-HeapDict
DEPENDS+=	${PYPKGPREFIX}-lmdb-[0-9]*:../../databases/py-lmdb

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m pytest

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
