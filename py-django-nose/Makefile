# $NetBSD: Makefile,v 1.2 2010/08/16 10:57:50 jihbed Exp $
#

DISTNAME=	django-nose-0.1.2
EGG_NAME=	django_nose-0.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel www
MASTER_SITES=	http://pypi.python.org/packages/source/d/django-nose/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pypi.python.org/packages/source/d/django-nose/
COMMENT=	Django test runner that uses nose
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-nose>=0.11.3:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC}/testapp && ${PYTHONBIN} runtests.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
