# $NetBSD: Makefile,v 1.2 2015/07/09 22:09:57 jihbed Exp $

DISTNAME=	radon-1.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/radon/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://radon.readthedocs.org/
COMMENT=	Code Metrics in Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-colorama>=0.3.2:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-nose>=1.3.4:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-cElementTree>=2.7.10:../../textproc/py-cElementTree
DEPENDS+=	${PYPKGPREFIX}-mando>=0.3.2:../../wip/py-mando

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}/radon/tests; ${SETENV} ${TEST_ENV} ${PYTHONBIN} run.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
