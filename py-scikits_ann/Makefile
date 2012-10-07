# $NetBSD: Makefile,v 1.3 2012/10/07 13:57:29 asau Exp $
#

DISTNAME=	scikits.ann-${PYPKGVERSION}
EGG_NAME=	${DISTNAME}
PKGNAME=	${PYPKGPREFIX}-scikits_ann-0.2
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/s/scikits.ann/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://scipy.org/scipy/scikits/wiki/AnnWrapper
COMMENT=	Approximate Nearest Neighbor library wrapper for Numpy
LICENSE=	gnu-lgpl-v3

#WRKSRC=		${WRKDIR}/scikits.ann-0.2.dev-r803

USE_LANGUAGES=	c++

PYPKGVERSION=	0.2.dev-r803
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
PLIST_SUBST+=	PYPKGVERSION=${PYPKGVERSION:S|-|_|}

do-test:
	${RUN} cd ${WRKSRC}/scikits/ann/tests; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_ann.py

.include "../../lang/python/egg.mk"
BUILDLINK_API_DEPENDS.pynumpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../wip/ann/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
