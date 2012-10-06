# $NetBSD: Makefile,v 1.2 2012/10/06 18:14:21 jihbed Exp $
#

DISTNAME=	isodate-0.4.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	http://pypi.python.org/packages/source/i/isodate/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://cheeseshop.python.org/pypi/isodate
COMMENT=	ISO 8601 date/time/duration parser and formater
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}/src/isodate/tests; ${SETENV} ${TEST_ENV} ${PYTHONBIN} __init__.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
