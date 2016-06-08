# $NetBSD: Makefile,v 1.5 2013/08/31 22:13:21 jihbed Exp $

DISTNAME=	algopy-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/algopy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://packages.python.org/algopy
COMMENT=	Taylor Arithmetic Computation and Algorithmic Differentiation
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/algopy-0.5.0

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}/algopy; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_utils.py

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
