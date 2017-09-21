# $NetBSD$

DISTNAME=	quadprog-0.1.6
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=q/quadprog/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rmcgibbo/quadprog
COMMENT=	Solver for a strictly convex quadratic program
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
