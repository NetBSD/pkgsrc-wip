# $NetBSD: Makefile,v 1.1 2014/05/05 22:17:48 jihbed Exp $

DISTNAME=	dj-static-0.0.5
EGG_NAME=	dj_static-0.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	https://pypi.python.org/packages/source/d/dj-static/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://pypi.python.org/packages/source/d/dj-static/
COMMENT=	Serve production static files with Django
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
