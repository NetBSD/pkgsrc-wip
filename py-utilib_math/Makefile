# $NetBSD: Makefile,v 1.1.1.1 2011/05/09 20:01:43 jihbed Exp $
#

VERSION=	3.0.4
DISTNAME=	pyutilib.math-${VERSION}
PKGNAME=	${PYPKGPREFIX}-utilib_math-${VERSION}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pyutilib.math/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pypi.python.org/packages/source/p/pyutilib.math/
COMMENT=	PyUtilib math utilities
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/pyutilib.math-3.0.4
USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}pyutilib/math/tests/; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_math.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
