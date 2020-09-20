# $NetBSD$

DISTNAME=	qiskit-0.20.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/1f/60/542761fb70fa8039a546512b870c99e467df2151ab42b5327ef7b26d2f0f/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/Qiskit/qiskit
COMMENT=	Software for developing quantum computing programs
LICENSE=	apache-2.0

PYTHON_VERSIONS_INCOMPATIBLE=   27

DEPENDS+=	${PYPKGPREFIX}-qiskit-terra>=0.15.2:../../wip/py-qiskit-terra
DEPENDS+=	${PYPKGPREFIX}-qiskit-aer>=0.6.1:../../wip/py-qiskit-aer
DEPENDS+=	${PYPKGPREFIX}-qiskit-ibmq-provider>=0.9.0:../../wip/py-qiskit-ibmq-provider
DEPENDS+=	${PYPKGPREFIX}-qiskit-ignis>==0.4.0:../../wip/py-qiskit-ignis
DEPENDS+=	${PYPKGPREFIX}-qiskit-aqua>=0.7.5:../../wip/py-qiskit-aqua

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
