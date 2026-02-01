# $NetBSD$

DISTNAME=	minidb-2.0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=thp/}
GITHUB_PROJECT=	minidb

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://thp.io/2010/minidb/
COMMENT=	Simple python object store
LICENSE=	isc

TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
TEST_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.32:../../devel/py-wheel
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC}/test && PYTHONPATH=.. ${PYTHONBIN} test_minidb.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
