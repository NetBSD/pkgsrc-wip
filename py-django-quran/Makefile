# $NetBSD: Makefile,v 1.3 2014/12/31 13:58:31 thomasklausner Exp $

DISTNAME=	django-quran-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-quran/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/idris/django-quran
COMMENT=	Quranic models and helpers for use in Django projects
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 0.1

USE_LANGUAGES=	# none

TEST_ENV+=	PYTHONPATH=${WRKSRC}/quran
do-test:
	${SETENV} ${TEST_ENV} ${PYTHONBIN} tests.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
