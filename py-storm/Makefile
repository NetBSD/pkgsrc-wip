# $NetBSD$

DISTNAME=	storm-0.24
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python devel
MASTER_SITES=	${MASTER_SITE_PYPI:=s/storm/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://storm.canonical.com
COMMENT=	Storm is an object-relational mapper (ORM)
LICENSE=	gnu-lgpl-v2

DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-fixtures>=1.3.0:../../devel/py-fixtures
TEST_DEPENDS+=	pgbouncer>=0.0.7:../../databases/pgbouncer
TEST_DEPENDS+=	${PYPKGPREFIX}-postgresfixture>=0.4.2../../devel/py-postgresfixture
TEST_DEPENDS+=	${PYPKGPREFIX}-psycopg2>=2.3.0:../../databases/py-sycopg2
TEST_DEPENDS+=	${PYPKGPREFIX}-testresources>=0.2.4:../../devel/py-testresources
TEST_DEPENDS+=	${PYPKGPREFIX}-testtools>=0.9.8:../../devel/py-testtools
TEST_DEPENDS+=	${PYPKGPREFIX}-timeline>=0.0.7../../devel/py-timeline
TEST_DEPENDS+=	${PYPKGPREFIX}-transaction>=1.0.0:../../wip/py-transaction
TEST_DEPENDS+=	${PYPKGPREFIX}-twisted>=10.0.0:../../net/py-twisted
TEST_DEPENDS+=	${PYPKGPREFIX}-ZopeComponent>=4.6.2../../devel/py-ZopeComponent
TEST_DEPENDS+=	${PYPKGPREFIX}-ZopeConfiguration>=4.4.0../../devel/py-ZopeConfiguration
TEST_DEPENDS+=	${PYPKGPREFIX}-ZopeInterface>=5.1.2../../devel/py-ZopeInterface
TEST_DEPENDS+=	${PYPKGPREFIX}-ZopeSecurity>=5.1.1../../wip/py-zopeSecurity

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
