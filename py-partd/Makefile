# $NetBSD$

DISTNAME=	partd-1.4.2
PKGREVISION=1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PYPI:=p/partd/}


MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/dask/partd/
COMMENT=	Key-Value byte store with appendable values
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=  27 38

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=68.2:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.41:../../devel/py-wheel

DEPENDS+=	${PYPKGPREFIX}-toolz>=0.8.2:../../devel/py-toolz
DEPENDS+=	${PYPKGPREFIX}-locket>=0.2.1:../../wip/py-locket
DEPENDS+=	${PYPKGPREFIX}-blosc2>=2.3.1:../../wip/py-blosc2
DEPENDS+=	${PYPKGPREFIX}-zmq>=0.2.1:../../net/py-zmq
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.9.0:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-pandas>=1.3.0:../../math/py-pandas


TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m pytest

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
