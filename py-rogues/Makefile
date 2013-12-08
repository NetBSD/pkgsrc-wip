# $NetBSD: Makefile,v 1.3 2013/12/08 16:11:10 jihbed Exp $

DISTNAME=	rogues-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/source/r/rogues/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/rogues
COMMENT=	Python and numpy port of Nicholas Higham's m*lab test matrices
LICENSE=	mit

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} rogues/matrices/tests/test_rogues.py*

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
