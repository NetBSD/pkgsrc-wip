# $NetBSD: Makefile,v 1.2 2012/10/07 11:54:27 asau Exp $
#

DISTNAME=	django-uuidfield-0.4.0
EGG_NAME=	django_uuidfield-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/d/django-uuidfield/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/dcramer/django-uuidfield
COMMENT=	UUIDField in Django
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

USE_LANGUAGES=	# none

PLIST_SUBST+=		EGG_INFODIR=${EGG_NAME}-py${PYVERSSUFFIX}.egg-info

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
