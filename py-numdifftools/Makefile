# $NetBSD: Makefile,v 1.5 2014/06/01 12:49:43 thomasklausner Exp $

DISTNAME=	Numdifftools-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/N/n/}
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/source/N/Numdifftools/
EXTRACT_SUFX=	.zip#md5=944981e22d56ff299f73124ea1e62edc

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/numdifftools/
COMMENT=	Tools for automatic numerical differentiation
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy

do-test:
	${RUN} cd ${WRKSRC}/numdifftools/test; ${SETENV} ${TEST_ENV} ${PYTHONBIN} testnumdifftools.py

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
