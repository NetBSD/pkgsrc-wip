# $NetBSD: Makefile,v 1.1.1.1 2011/01/19 14:30:11 jihbed Exp $
#

DISTNAME=	scikits.ann-0.2.dev-r803
EGG_NAME=	scikits.ann-0.2.dev_r803
PKGNAME=	${PYPKGPREFIX}-scikits_ann-0.2
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/s/scikits.ann/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://scipy.org/scipy/scikits/wiki/AnnWrapper
COMMENT=	Approximate Nearest Neighbor library wrapper for Numpy
LICENSE=	gnu-lgpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/scikits.ann-0.2.dev-r803

USE_LANGUAGES=	c++

do-test:
	${RUN} cd ${WRKSRC}/scikits/ann/tests; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_ann.py

.include "../../lang/python/egg.mk"
BUILDLINK_API_DEPENDS.pynumpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../wip/ann/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
