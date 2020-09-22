# $NetBSD$

DISTNAME=	symphysics-0.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/97/9e/21ac590f308a8b9f6a791e2b2c6ce7dc75e18450ed356a55ceedd46e1375/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/rjbourne/symphysics/
COMMENT=	The symphysics library for creating physics simulations using python and sympy
LICENSE=	mit

DEPENDS+=       ${PYPKGPREFIX}-matplotlib>=3.2.2:../../graphics/py-matplotlib
DEPENDS+=       ${PYPKGPREFIX}-scipy>=1.2.3:../../math/py-scipy
DEPENDS+=       ${PYPKGPREFIX}-sympy>=1.6.2:../../math/py-sympy
DEPENDS+=       ${PYPKGPREFIX}-dill>=0.3.2:../../wip/py-dill

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
