# $NetBSD: Makefile,v 1.2 2012/10/07 11:54:23 asau Exp $
#

DISTNAME=	django-audiofield-0.4.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www audio python
MASTER_SITES=	http://pypi.python.org/packages/source/d/django-audiofield/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://github.com/Star2Billing/django-audiofield
COMMENT=	Allows audio file upload and conversion to mp3, wav and ogg format
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-uuidfield>=0.4.0:../../wip/py-django-uuidfield

WRKSRC=			${WRKDIR}/django-audiofield-0.4.6

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
