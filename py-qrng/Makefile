# $NetBSD$

DISTNAME=	qrng-0.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/e2/98/1682774ffff95e5387a54c0efb05b30b9338ac3a4fa0872a67c62db2dd65/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/ozanerhansha/qRNG
COMMENT=	Quantum Random Number Generator using IBM's Qiskit
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-qiskit>=0.20.1:../../wip/py-qiskit

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
