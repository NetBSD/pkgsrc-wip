# $NetBSD$

DISTNAME=	mathopt-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mathopt/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/CalebBell/mathopt
COMMENT=	Optimize mathematical formulas for speed with SymPy
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE+=	27

DEPENDS+=	${PYPKGPREFIX}-sympy>=1.7:../../math/py-sympy

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
