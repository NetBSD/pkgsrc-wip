# $NetBSD: Makefile,v 1.4 2012/10/06 17:13:30 asau Exp $
#

DISTNAME=	algopy-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/a/algopy/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://packages.python.org/algopy
COMMENT=	Taylor Arithmetic Computation and Algorithmic Differentiation
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}/algopy; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_utils.py

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
