# $NetBSD: Makefile,v 1.2 2014/12/31 13:58:27 thomasklausner Exp $

DISTNAME=	dj-static-0.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dj-static/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	${MASTER_SITE_PYPI:=d/dj-static/}
COMMENT=	Serve production static files with Django
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
