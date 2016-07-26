# $NetBSD$

DISTNAME=	radon-1.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/radon/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://radon.readthedocs.org/
COMMENT=	Code Metrics in Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-colorama>=0.3.2:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-cElementTree>=2.7.10:../../textproc/py-cElementTree
DEPENDS+=	${PYPKGPREFIX}-flake8-polyfill>=1.0.1:../../wip/py-flake8-polyfill
DEPENDS+=	${PYPKGPREFIX}-mando>=0.4:../../wip/py-mando

WRKSRC=		${WRKDIR}/radon-1.4.2

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}/radon/tests; ${SETENV} ${TEST_ENV} ${PYTHONBIN} run.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
