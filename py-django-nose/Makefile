# $NetBSD: Makefile,v 1.1.1.1 2010/08/09 21:42:28 jihbed Exp $
#

DISTNAME=	django-nose-0.1.tar
EGG_NAME=	django_nose-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/.tar//}
CATEGORIES=	devel www
MASTER_SITES=	http://pypi.python.org/packages/source/d/django-nose/
EXTRACT_SUFX=	.gz

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pypi.python.org/packages/source/d/django-nose/
COMMENT=	Django test runner that uses nose
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-nose>=0.11.3:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/django-nose-0.1
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
