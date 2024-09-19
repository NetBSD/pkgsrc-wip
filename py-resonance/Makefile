# $NetBSD$

DISTNAME=	resonance-0.22.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/f9/e9/04628aa8a4feb2c177539e347b7139fcbafdc7da9958fb5a392bdd6481d5/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/moorepants/resonance/
COMMENT=	Learning mechanical vibrations through computation
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-matplotlib>=2.1:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.17:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.19:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-sympy>=1.5.1:../../math/py-sympy

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.13
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
