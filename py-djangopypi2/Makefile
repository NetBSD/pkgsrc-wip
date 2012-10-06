# $NetBSD: Makefile,v 1.1 2012/10/06 23:23:21 jihbed Exp $
#

DISTNAME=	djangopypi2-0.5.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://pypi.python.org/packages/source/d/djangopypi2/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://github.com/benliles/djangopypi/
COMMENT=	Django application that emulates the Python Package Index
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-docutils>=0.9:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

WRKSRC=		${WRKDIR}/djangopypi2-0.5.4

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
