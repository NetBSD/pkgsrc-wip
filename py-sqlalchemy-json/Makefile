# $NetBSD$

DISTNAME=	sqlalchemy-json-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	https://files.pythonhosted.org/packages/f0/8b/a8efb371baa9367751319ce60bdd258fbf292306d11c389182544ae6844a/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/edelooff/sqlalchemy-json
COMMENT=	JSON type with nested change tracking for SQLAlchemy
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.7:../../databases/py-sqlalchemy

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
