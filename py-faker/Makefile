# $NetBSD: Makefile,v 1.2 2015/04/13 23:22:02 othyro Exp $

DISTNAME=	Faker-0.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.python.org/packages/source/F/Faker/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/deepthawtz/faker
COMMENT=	Library for generating fake user data
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 34 33 27

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
