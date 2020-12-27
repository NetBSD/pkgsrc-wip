# $NetBSD$

DISTNAME=	sqlitedict-1.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sqlitedict}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/RaRe-Technologies/sqlitedict
COMMENT=	Persistent dict in Python, backed up by sqlite3 and pickle, multithread-safe
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-sqlite3>=3.7.9:../../databases/py-sqlite3

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
