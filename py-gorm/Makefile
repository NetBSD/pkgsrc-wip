# $NetBSD$

DISTNAME=	gorm-0.7.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gorm/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/LogicalDash/gorm
COMMENT=	Mapper serving database-backed of the networkx graph classes
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-networkx>=1.11:../../math/py-networkx

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # py-networkx

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
