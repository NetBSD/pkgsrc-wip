# $NetBSD$

DISTNAME=	qiskit-terra-0.15.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/7a/5b/3a26a3c2ce08bc6eed380874b7e33f6cb7d7c2b9699340486b08b3f9f18c/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/Qiskit/qiskit-terra/
COMMENT=	Software for developing quantum computing programs
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++

DEPENDS+=       ${PYPKGPREFIX}-matplotlib>=3.2.2:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-networkx>=0.5.0:../../math/py-networkx
DEPENDS+=       ${PYPKGPREFIX}-sympy>=1.5.1:../../math/py-sympy
DEPENDS+=       ${PYPKGPREFIX}-dill>=0.3.2:../../wip/py-dill


.include "../../devel/py-cython/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
