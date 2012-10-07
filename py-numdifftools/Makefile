# $NetBSD: Makefile,v 1.3 2012/10/07 12:25:33 asau Exp $
#

DISTNAME=	Numdifftools-0.3.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/N/n/}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/N/Numdifftools/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/numdifftools/
COMMENT=	Tools for automatic numerical differentiation
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}/numdifftools/test; ${SETENV} ${TEST_ENV} ${PYTHONBIN} testnumdifftools.py

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
