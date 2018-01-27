# $NetBSD$

DISTNAME=	lmfit-0.9.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/c6/4a/75f188877264b6f9e8f2d68f213d2c7329bcb3a86be013fa11c1d256990e/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://lmfit.github.io/lmfit-py/
COMMENT=	Least-Squares Minimization with Bounds and Constraints
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.0:../../math/py-scipy

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
