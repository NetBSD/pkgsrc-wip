# $NetBSD: Makefile,v 1.2 2012/10/07 11:54:26 asau Exp $
#

DISTNAME=	django-quran-0.1.tar
EGG_NAME=	django_quran-0.1
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	www
MASTER_SITES=	http://pypi.python.org/packages/source/d/django-quran/
EXTRACT_SUFX=	.gz

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://github.com/idris/django-quran
COMMENT=	Quranic models and helpers for use in Django projects
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

WRKSRC=		${WRKDIR}/django-quran-0.1
USE_LANGUAGES=	# none

TEST_ENV+=	PYTHONPATH=${WRKSRC}/quran
do-test:
	${SETENV} ${TEST_ENV} ${PYTHONBIN} tests.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
