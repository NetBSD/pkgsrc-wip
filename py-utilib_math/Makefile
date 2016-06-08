# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:32 asau Exp $
#

VERSION=	3.0.4
DISTNAME=	pyutilib.math-${VERSION}
PKGNAME=	${PYPKGPREFIX}-utilib_math-${VERSION}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyutilib.math/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	${MASTER_SITE_PYPI:=p/pyutilib.math/}
COMMENT=	PyUtilib math utilities
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/pyutilib.math-3.0.4
USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}pyutilib/math/tests/; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_math.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
