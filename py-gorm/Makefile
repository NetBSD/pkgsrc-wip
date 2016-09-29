# $NetBSD$

DISTNAME=	gorm-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://pypi.python.org/packages/4f/d8/33ac12feedca93865b1105b229b959e360388bd14d38882eb62572bda1fe/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/LogicalDash/gorm
COMMENT=	Database-backed versions of the standard networkx graph classes
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=1.0.15:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-networkx>=1.11:../../math/py-networkx

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
