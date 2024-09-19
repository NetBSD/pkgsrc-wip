# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:29 asau Exp $
#

DISTNAME=	scikits.bvp1lg-0.2.5
PKGNAME=	${PYPKGPREFIX}-scikits_bvp1lg-0.2.5
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scikits.bvp1lg/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.iki.fi/pav/software/bvp
COMMENT=	Boundary value problem (legacy) solvers for ODEs
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-nose>=0.11.3:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy

USE_LANGUAGES=	c fortran

do-test:
	${RUN} cd ${WRKSRC}/scikits/bvp1lg/tests/; ${SETENV} ${TEST_ENV} ${PYTHONBIN} testutils.py

.include "../../lang/python/egg.mk"
BUILDLINK_API_DEPENDS.pynumpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
