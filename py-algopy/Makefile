# $NetBSD: Makefile,v 1.3 2012/09/10 23:23:09 jihbed Exp $
#

DISTNAME=	algopy-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/a/algopy/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://packages.python.org/algopy
COMMENT=	Taylor Arithmetic Computation and Algorithmic Differentiation
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}/algopy; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_utils.py

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
