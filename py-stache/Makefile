# $NetBSD: Makefile,v 1.1 2015/07/04 03:57:42 jihbed Exp $

DISTNAME=	pystache-0.5.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S//py/}
CATEGORIES=	www
MASTER_SITES=	https://pypi.python.org/packages/source/p/pystache/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://pypi.python.org/packages/source/p/pystache/
COMMENT=	Mustache for Python
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 34 33 27

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_pystache.py


.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
