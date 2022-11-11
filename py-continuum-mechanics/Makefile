# $NetBSD$

DISTNAME=	continuum_mechanics-0.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/continuum_mechanics/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/nicoguaro/continuum_mechanics
COMMENT=	Utilities for doing calculations in continuum mechanics
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGRPEFIX}-test-runner>=5.2:../../devel/py-test-runner
DEPENDS+=	${PYPKGPREFIX}-sympy>=1.3:../../math/py-sympy
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.9.3:../../math/py-scipy
TEST_DEPENDS+=	${PYPKGRPEFIX}-test>=7.2.0:../../devel/py-test

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
