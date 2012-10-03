# $NetBSD: Makefile,v 1.1 2012/10/03 23:58:06 jihbed Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PLIST_SUBST+=		EGG_INFODIR=${EGG_NAME}-py${PYVERSSUFFIX}.egg-info

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
