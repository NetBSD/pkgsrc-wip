# $NetBSD$

DISTNAME=	meshio-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=m/meshio/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/nschloe/meshio
COMMENT=	I/O for various mesh formats
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-h5py>=2.5.0:../../devel/py-h5py
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.5.0:../../textproc/py-lxml

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}/test; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test.py

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
