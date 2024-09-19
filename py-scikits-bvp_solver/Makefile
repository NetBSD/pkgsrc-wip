# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:29 asau Exp $
#

DISTNAME=	scikits.bvp_solver-0.3.0
PKGNAME=	${PYPKGPREFIX}-scikits-bvp_solver-0.3.0
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scikits.bvp_solver/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://packages.python.org/scikits.bvp_solver/
COMMENT=	Python package for solving two-point boundary value problems
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-nose>=0.11.3:../../devel/py-nose

WRKSRC=		${WRKDIR}/scikits.bvp_solver-0.3.0

USE_LANGUAGES=	c fortran

.include "../../lang/g95/buildlink3.mk"
.include "../../lang/python/egg.mk"
BUILDLINK_API_DEPENDS.pynumpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
