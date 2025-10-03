# $NetBSD$

DISTNAME=	sqlite_utils-3.38
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sqlite_utils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/simonw/sqlite-utils
COMMENT=	CLI tool and Python library for manipulating SQLite databases
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-click-default-group>=1.2.3:../../devel/py-click-default-group
DEPENDS+=	${PYPKGPREFIX}-click>=0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-dateutil>=0:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-pluggy>=0:../../devel/py-pluggy
DEPENDS+=	${PYPKGPREFIX}-sqlite-fts4>=0:../../wip/py-sqlite-fts4
DEPENDS+=	${PYPKGPREFIX}-tabulate>=0:../../textproc/py-tabulate

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} sqlite-utils sqlite-utils${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
