# $NetBSD$

DISTNAME=	minidb-2.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=thp/}
GITHUB_PROJECT=	minidb

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://thp.io/2010/minidb/
COMMENT=	Simple python object store
LICENSE=	isc

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC}/test && PYTHONPATH=.. ${PYTHONBIN} test_minidb.py

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
