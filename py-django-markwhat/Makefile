# $NetBSD$

DISTNAME=	django-markwhat-1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-markwhat/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pypi.python.org/pypi/django-markwhat
COMMENT=	Template filters that implement common markup languages
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}/django_markwhat; ${SETENV} ${TEST_ENV} ${PYTHONBIN} tests.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
