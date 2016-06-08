# $NetBSD: Makefile,v 1.3 2015/04/14 11:56:21 thomasklausner Exp $

DISTNAME=	Faker-0.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Faker/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/deepthawtz/faker
COMMENT=	Library for generating fake user data
LICENSE=	mit

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
