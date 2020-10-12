# $NetBSD: Makefile,v 1.1 2014/10/21 21:28:24 jihbed Exp $

DISTNAME=	cvxpy-0.2.15
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cvxpy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/cvxgrp/cvxpy/
COMMENT=	Python software for convex optimization
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/blas.buildlink3.mk"
.include "../../math/glpk/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
