# $NetBSD$

DISTNAME=	factory_boy-3.1.0
PKGNAME=	${PYPKGPREFIX}-factory-boy-3.1.0
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/factory_boy/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/FactoryBoy/factory_boy	
COMMENT=	Test fixtures replacement for Python
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=1.3.20:../../databases/py-sqlalchemy

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
