# $NetBSD$

DISTNAME=	sqlalchemy-stubs-0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sqlalchemy-stubs/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/dropbox/sqlalchemy-stubs
COMMENT=	SQLAlchemy stubs and mypy plugin
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-mypy>=0.720:../../lang/py-mypy
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.7.4:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
