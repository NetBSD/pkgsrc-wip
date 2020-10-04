# $NetBSD$

DISTNAME=	quaternionic-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/2e/a2/7b66eea0efca49203b3296ea68b268484a1890415298e9e925ee3c3c144a/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/moble/quaternionic
COMMENT=	Interpret numpy arrays as quaternionic arrays with numba acceleration
LICENSE=	mit

<<<<<<< HEAD:py-quaternionic/Makefile
#DEPENDS+=	${PYPKGPREFIX}-scipy>=1.5.2:../../math/py-scipy
=======
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.5.1:../../math/py-scipy
>>>>>>> a91416307c74d27c8a0ada48f7b1fbd2c114a36f:DONE/py-quaternionic/Makefile

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>=1.13
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
