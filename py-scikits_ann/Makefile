# $NetBSD: Makefile,v 1.4 2012/10/16 08:32:49 thomasklausner Exp $

DISTNAME=	scikits.ann-${PYPKGVERSION}
EGG_NAME=	${DISTNAME}
PKGNAME=	${PYPKGPREFIX}-scikits_ann-0.2
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scikits.ann/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://scipy.org/scipy/scikits/wiki/AnnWrapper
COMMENT=	Approximate Nearest Neighbor library wrapper for Numpy
LICENSE=	gnu-lgpl-v3

BUILD_DEPENDS+=	swig-[0-9]*:../../devel/swig

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # as of 0.2.dev-r803, uses ConfigParser

USE_LANGUAGES=	c c++

PYPKGVERSION=	0.2.dev-r803
PLIST_SUBST+=	PYPKGVERSION=${PYPKGVERSION:S|-|_|}

do-test:
	${RUN} cd ${WRKSRC}/scikits/ann/tests; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_ann.py

.include "../../lang/python/egg.mk"
BUILDLINK_API_DEPENDS.pynumpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../wip/ann/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
