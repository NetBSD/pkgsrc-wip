# $NetBSD$

DISTNAME=	handy-0.5.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=h/handy/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://github.com/Suor/handy
COMMENT=	Collection of tools to make your django life easier
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
