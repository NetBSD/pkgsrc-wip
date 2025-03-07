# $NetBSD$

DISTNAME=	django-crispy-forms-1.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-crispy-forms/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/maraujop/django-crispy-forms
COMMENT=	Best way to have Django DRY forms
LICENSE=	mit


DEPENDS+=	${PYPKGPREFIX}-django>=1.11:../../www/py-django

.include "../../lang/python/egg.mk"
WRKSRC=		${WRKDIR}/django-crispy-forms-1.7.2
USE_LANGUAGES=	# none

.include "../../mk/bsd.pkg.mk"
