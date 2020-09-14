# $NetBSD$

DISTNAME=	toleranceinterval-0.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/b9/1e/f9732ca98c49ffcdc123991e5ea65a295c4026d8bc3a3edd0e07c09397a0/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/cjekel/tolerance_interval_py
COMMENT=	Library for one-sided bounds and two-sided tolerance intervals
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-scipy>=1.4.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-sympy>=1.5.1:../../math/py-sympy

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.14.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
