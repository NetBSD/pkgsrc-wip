# $NetBSD: Makefile,v 1.3 2015/01/31 17:12:20 jihbed Exp $

DISTNAME=	path.py-10.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/path.py/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/jaraco/path.py
COMMENT=	Module wrapper for os.path
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-appdirs-[0-9]*:../../devel/py-appdirs
BUILD_DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
BUILD_DEPENDS+=	${PYPKGPREFIX}-test>=2.8:../../devel/py-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-sugar-[0-9]*:../../devel/py-test-sugar

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_path.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
