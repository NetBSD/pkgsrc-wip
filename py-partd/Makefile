# $NetBSD$

DISTNAME=	partd-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PYPI:=p/partd/}


MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/dask/partd/
COMMENT=	Key-Value byte store with appendable values
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-toolz>=0.8.2:../../devel/py-toolz
DEPENDS+=	${PYPKGPREFIX}-locket>=0.2.1:../../wip/py-locket
DEPENDS+=	${PYPKGPREFIX}-blosc>=0.2.1:../../wip/py-blosc
DEPENDS+=	${PYPKGPREFIX}-zmq>=0.2.1:../../net/py-zmq


TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m pytest

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
