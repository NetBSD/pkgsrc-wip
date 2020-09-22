# $NetBSD$

DISTNAME=	qclib-0.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/59/6d/a8c0b8ed95031c5210265e9c621aedebd87da0a69569579266597055058e/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/qclib/qclib
COMMENT=	Quantum computing library using qiskit
#LICENSE=	# TODO: (see mk/license.mk)

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	38 37

#DEPENDS+=	${PYPKGPREFIX}-qiskit>=0.20.1:../../wip/py-qiskit

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} -m unittest test/test_encoding.py

BUILDLINK_API_DEPENDS.py-numpy+=        ${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
