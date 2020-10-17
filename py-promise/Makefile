# $NetBSD$

DISTNAME=	promise-2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/promise/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/syrusakbary/promise
COMMENT=	Promises/A+ implementation for Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.0.2:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.10.1:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-coveralls>=2.4.2:../../wip/py-coveralls
TEST_DEPENDS+=	${PYPKGPREFIX}-futures>=3.0.1:../../devel/py-futures
TEST_DEPENDS+=	${PYPKGPREFIX}-test-benchmark>=0:../../devel/py-test-benchmark
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=3.0.5:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0.14.0:../../devel/py-test-asyncio


.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
