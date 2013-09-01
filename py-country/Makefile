# $NetBSD: Makefile,v 1.1 2013/09/01 18:39:45 jihbed Exp $

DISTNAME=	pycountry-0.19
PKGNAME=        ${PYPKGPREFIX}-country-0.19
CATEGORIES=	misc
MASTER_SITES=	https://pypi.python.org/packages/source/p/pycountry/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://pypi.python.org/packages/source/p/pycountry/
COMMENT=	ISO country, subdivision, language, currency and script
LICENSE=	gnu-lgpl-v2.1

FETCH_USING=	curl

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

do-test:
	${RUN} cd ${WRKSRC}/src/pycountry; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_general.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
