# $NetBSD$

DISTNAME=	quantuminspire-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/f1/e3/a5f13460084584b5f43426ae2e788bef296476efdd074ded7d875379de31/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pypi.org/project/quantuminspire/
COMMENT=	SDK for the Quantum Inspire platform
LICENSE=	apache-2.0

DEPENDS+=	# TODO: pytest>=3.3.1
DEPENDS+=	${PYPKGPREFIX}-coverage>=4.5.1:../../devel/py-coverage
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=2.1:../../graphics/py-matplotlib
DEPENDS+=	# TODO: coreapi>=2.3.3
DEPENDS+=	# TODO: jupyter>=0
DEPENDS+=	# TODO: nbimporter>=0
DEPENDS+=	# TODO: sklearn>=0

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.16.3
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
