# $NetBSD$

DISTNAME=	minidb-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	https://thp.io/2010/minidb/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://thp.io/2010/minidb/
COMMENT=	Simple python object store
LICENSE=	isc

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
