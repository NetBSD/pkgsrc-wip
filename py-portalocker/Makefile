# $NetBSD$

DISTNAME=	portalocker-2.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/portalocker/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/WoLpH/portalocker/
COMMENT=	Python library for file locking
LICENSE=	python-software-foundation

DEPENDS+=	${PYPKGPREFIX}-redis-[0-9]*:../../databases/py-redis
# needs a running redis database
TEST_DEPENDS+=	${PYPKGPREFIX}-sphinx>=3.0.3:../../textproc/py-sphinx
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=5.4.1:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.8.1:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=2.1.0:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mypy>=0.8.0:../../devel/py-test-mypy

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
