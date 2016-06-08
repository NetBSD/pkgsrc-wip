# $NetBSD: Makefile,v 1.1 2015/01/26 18:15:54 jihbed Exp $

DISTNAME=	blessings-1.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=b/blessings/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/erikrose/blessings
COMMENT=	Practical wrapper around terminal coloring, styling
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # py-multiprocessing

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test.py

DEPENDS+=	${PYPKGPREFIX}-multiprocessing>=2.6.2.1:../../devel/py-multiprocessing
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
