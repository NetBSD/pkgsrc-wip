# $NetBSD$

DISTNAME=	postgresfixture-0.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/postgresfixture/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://pypi.org/project/postgresfixture/
COMMENT=	Fixture for creating PostgreSQL clusters and databases
LICENSE=	gnu-agpl-v3

DEPENDS+=	${PYPKGPREFIX}-fixtures>=0.3.8:../../devel/py-fixtures
DEPENDS+=	${PYPKGPREFIX}-psycopg2>=2.4.4:../../databases/py-psycopg2
DEPENDS+=	${PYPKGPREFIX}-testtools>=0.9.14:../../devel/py-testtools
DEPENDS+=	${PYPKGPREFIX}-testscenarios>=0.4:../../devel/py-testscenarios
TEST_DEPENDS+=	${PYPKGPREFIX}-testtools>=0.9.14:../../devel/py-testtools

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
