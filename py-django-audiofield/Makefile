# $NetBSD: Makefile,v 1.3 2012/10/27 16:52:10 noud4 Exp $
#

DISTNAME=	django-audiofield-0.4.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-audiofield/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://github.com/Star2Billing/django-audiofield
COMMENT=	Allows audio file upload and conversion to mp3, wav and ogg format
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-uuidfield>=0.4.0:../../wip/py-django-uuidfield

WRKSRC=			${WRKDIR}/django-audiofield-0.4.6

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

PLIST_SUBST+=	THIS_EGG_INFODIR=${EGG_NAME:S|django-|django_|}-py${PYVERSSUFFIX}.egg-info

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
