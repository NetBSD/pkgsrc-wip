# $NetBSD: Makefile,v 1.1 2015/07/04 03:57:42 jihbed Exp $

DISTNAME=	pystache-0.5.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S//py/}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pystache/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://files.pythonhosted.org/packages/source/p/pystache/
COMMENT=	Mustache for Python
LICENSE=	mit

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_pystache.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
