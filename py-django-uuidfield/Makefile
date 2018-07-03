# $NetBSD: Makefile,v 1.4 2014/12/31 13:58:31 thomasklausner Exp $

DISTNAME=	django-uuidfield-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-uuidfield/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/dcramer/django-uuidfield
COMMENT=	UUIDField in Django
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 0.4.0

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
