# $NetBSD$

DISTNAME=	RxPy3-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=R/RxPy3/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://reactivex.io
COMMENT=	Reactive Extensions (Rx) for Python, aliased for Rx3
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-test>=4.6.1:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0.10.0:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=4.5.3:../../devel/py-coverage

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
