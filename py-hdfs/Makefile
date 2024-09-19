# $NetBSD$

VERS=		2.5.8
DISTNAME=	hdfs-${VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/${DISTNAME:S/${VERS}//}/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://hdfscli.readthedocs.io/
COMMENT=	HdfsCLI: API and command line interface for HDFS
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-docopt>=0.6.2:../../devel/py-docopt
DEPENDS+=	${PYPKGPREFIX}-requests>=2.24.0:../../devel/py-requests
DEPENDS+=       ${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six
DEPENDS+=       ${PYPKGPREFIX}-fastavro>=1.0.0:../../wip/py-fastavro
TEST_DEPENDS+=	${PYPKGPREFIX}-nose>=1.3.7:../../devel/py-nose

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}/test; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_main.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
