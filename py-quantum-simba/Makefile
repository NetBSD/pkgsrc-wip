# $NetBSD$

DISTNAME=	quantum-simba-0.9.6.dev0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/8a/2b/32ad04ebb23e7bafa963f0af1ada8486871376d767cca0f7c5a3c0d68a14/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/joebentley/simba
COMMENT=	Systematic Inference of Bosonic quAntum systems
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-scipy>=1.4.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-sympy>=1.5.1:../../math/py-sympy
DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
