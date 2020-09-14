# $NetBSD$

DISTNAME=	django-sympycharfield-0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www math python
MASTER_SITES=	https://files.pythonhosted.org/packages/3b/f1/4a9fcd296161b810884ff32573c65dc090b68d4dc167f3d7c7bbe2ee7e9c/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/memoriadecalculo/django-sympycharfield
COMMENT=	Django Char Field using Sympy
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-sympy>=1.5.1:../../math/py-sympy
DEPENDS+=	${PYPKGPREFIX}-django>=1.11.29:../../www/py-django

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
