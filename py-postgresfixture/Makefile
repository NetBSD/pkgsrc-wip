# $NetBSD$

DISTNAME=	postgresfixture-0.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	https://files.pythonhosted.org/packages/d9/23/9c687e856c9d378580e93fe13b57ff7222fcb92ab98592cf8fbe378a36a9/

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
