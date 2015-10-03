# $NetBSD$

DISTNAME=	inflection-0.3.1
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	https://pypi.python.org/packages/source/i/inflection/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://github.com/jpvanhal/inflection
COMMENT=	A port of Ruby on Rails inflector to Python
LICENSE=	mit

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_inflection.py
	
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
