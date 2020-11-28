# $NetBSD$

DISTNAME=	testfixtures-6.15.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/testfixtures/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/Simplistix/testfixtures
COMMENT=	Collection of helpers and mock objects for unit tests and doc tests
LICENSE=	mit

USE_LANGUAGES=	# none

BUILD_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.29.0:../../devel/py-wheel
BUILD_DEPENDS+=	${PYPKGPREFIX}-twine>=1.13.0:../../net/py-twine
DEPENDS+=	${PYPKGPREFIX}-test>=6.1.2:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.10.1:../../devel/py-test-cov
DEPENDS+=	${PYPKGPREFIX}-test-django>=3.10.0:../../www/py-test-django

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
