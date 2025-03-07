# $NetBSD$

DISTNAME=	django-sympycharfield-0.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www math python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-sympycharfield/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/memoriadecalculo/django-sympycharfield
COMMENT=	Django Char Field using Sympy
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-sympy>=1.5.1:../../math/py-sympy
DEPENDS+=	${PYPKGPREFIX}-django>=1.11.29:../../www/py-django

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
