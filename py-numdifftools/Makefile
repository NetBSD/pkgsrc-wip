# $NetBSD: Makefile,v 1.4 2013/12/02 00:20:43 jihbed Exp $

DISTNAME=	Numdifftools-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/N/n/}
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/source/N/Numdifftools/
EXTRACT_SUFX=	.zip#md5=944981e22d56ff299f73124ea1e62edc
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/numdifftools/
COMMENT=	Tools for automatic numerical differentiation
LICENSE=	modified-bsd

do-test:
	${RUN} cd ${WRKSRC}/numdifftools/test; ${SETENV} ${TEST_ENV} ${PYTHONBIN} testnumdifftools.py

# url2pkg-marker (please do not remove this line.)
.include "../../lang/python/egg.mk"
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
