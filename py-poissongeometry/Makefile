# $NetBSD$

DISTNAME=	poissongeometry-0.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/9c/da/4c52bc7bc809004f2fdedf5bed22132008a4f9d73da295a591c55fcf616a/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/appliedgeometry/poisson_geometry
COMMENT=	Local Poisson-Nijenhuis calculus on Poisson manifolds
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-sympy>=1.6.2:../../math/py-sympy
DEPENDS+=	${PYPKGPREFIX}-galgebra>=0.5.0:../../wip/py-galgebra

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
