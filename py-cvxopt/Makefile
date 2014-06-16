# $NetBSD: Makefile,v 1.5 2014/06/16 00:22:39 jihbed Exp $

DISTNAME=	1.1.7
PKGNAME=	${PYPKGPREFIX}-cvxopt-${DISTNAME}
EGG_NAME=	cvxopt-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://github.com/cvxopt/cvxopt/archive/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://cvxopt.org/
COMMENT=	Python software for convex optimization
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/cvxopt-1.1.7

USE_LANGUAGES=	c fortran

.include "../../lang/python/egg.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../math/glpk/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
