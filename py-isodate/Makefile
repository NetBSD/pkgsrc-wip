# $NetBSD: Makefile,v 1.4 2013/12/05 20:08:57 jihbed Exp $

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
PYTHON_VERSIONS_INCLUDE_3X= yes

do-test:
	${RUN} cd ${WRKSRC}/src/isodate/tests; ${SETENV} ${TEST_ENV} ${PYTHONBIN} __init__.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
