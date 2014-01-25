# $NetBSD: Makefile,v 1.5 2014/01/25 10:38:20 thomasklausner Exp $

DISTNAME=	isodate-0.4.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	https://pypi.python.org/packages/source/i/isodate/
FETCH_USING=	curl

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://cheeseshop.python.org/pypi/isodate
COMMENT=	ISO 8601 date/time/duration parser and formater
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}/src/isodate/tests; ${SETENV} ${TEST_ENV} ${PYTHONBIN} __init__.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
