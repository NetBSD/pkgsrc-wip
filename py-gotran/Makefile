# $NetBSD$

DISTNAME=	gotran-2020.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/94/c9/2c28199cadebb1bd4b104b4b09b4c73067be124e6b31703eefeb1f0b19b1/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/ComputationalPhysiology/gotran
COMMENT=	Declarative language describing ordinary differential equations
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-future>=0:../../devel/py-future
DEPENDS+=       ${PYPKGPREFIX}-sympy>=1.5.1:../../math/py-sympy
DEPENDS+=       ${PYPKGPREFIX}-scipy>=1.5.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=0:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-networkx>=0:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-six>=0:../../lang/py-six
DEPENDS+=	#${PYPKGPREFIX}-modelparameters>=0:../../wip/py-modelparameters
DEPENDS+=	#${PYPKGPREFIX}-instant>=0:../../wip/py-instant

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
