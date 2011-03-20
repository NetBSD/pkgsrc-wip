# $NetBSD: Makefile,v 1.1.1.1 2011/03/20 22:33:37 jihbed Exp $
#

DISTNAME=	Numdifftools-0.3.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/N/n/}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/N/Numdifftools/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.comE
HOMEPAGE=	http://code.google.com/p/numdifftools/
COMMENT=	Tools for automatic numerical differentiation
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}/numdifftools/test; ${SETENV} ${TEST_ENV} ${PYTHONBIN} testnumdifftools.py

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
