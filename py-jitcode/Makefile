# $NetBSD$

DISTNAME=	jitcode-0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jitcode/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/neurophysik/jitcode
COMMENT=	Just-in-Time Compilation for Ordinary Differential Equations
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.17.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-sympy>=1.0:../../math/py-sympy

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
