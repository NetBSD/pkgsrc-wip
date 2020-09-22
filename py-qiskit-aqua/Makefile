# $NetBSD$

DISTNAME=	qiskit-aqua-0.7.5
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/a2/a3/1faadc428c2c2a1404c3b86b16369b7ddc5037429e6cb7926c57489e6e86/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/Qiskit/qiskit-aqua/
COMMENT=	Qiskit Aqua: An extensible library of quantum computing algorithms
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-h5py>=2.9.0:../../devel/py-h5py
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.25.3:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-networkx>=2.4:../../math/py-networkx
DEPENDS+=       ${PYPKGPREFIX}-scipy>=1.5.2:../../math/py-scipy
DEPENDS+=       ${PYPKGPREFIX}-sympy>=1.6.2:../../math/py-sympy
DEPENDS+=	${PYPKGPREFIX}-docplex>=2.15.194:../../wip/py-docplex
DEPENDS+=	${PYPKGPREFIX}-dlx>=1.0.4:../../wip/py-dlx
DEPENDS+=	${PYPKGPREFIX}-fastdtw>=0.3.4:../../wip/py-fastdtw
DEPENDS+=	${PYPKGPREFIX}-qiskit-ignis>=0.4.0:../../wip/py-qiskit-ignis
DEPENDS+=	${PYPKGPREFIX}-qiskit-terra>=0.15.0:../../wip/py-qiskit-terra
DEPENDS+=	${PYPKGPREFIX}-quandl>=3.5.2:../../wip/py-quandl
DEPENDS+=	${PYPKGPREFIX}-yfinance>=0.1.54:../../wip/py-yfinance

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
