# $NetBSD$

DISTNAME=	qiskit-ignis-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/c0/69/27467e0cbed1de7509fca1d8bc1e4ef3eb8a3b6eb50fc51694c1559602a3/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/Qiskit/qiskit-ignis/
COMMENT=	Qiskit tools for quantum information science
LICENSE=	apache-2.0

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-scipy>=1.5.2:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-scikit-learn>=0.22.1:../../math/py-scikit-learn
DEPENDS+=	${PYPKGPREFIX}-qiskit-terra>=0.15.2:../../wip/py-qiskit-terra

BUILDLINK_API_DEPENDS.py-numpy+=        ${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
