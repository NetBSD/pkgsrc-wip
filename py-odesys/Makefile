# $NetBSD$

DISTNAME=	pyodesys-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyodesys/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/bjodah/pyodesys
COMMENT=	Straightforward numerical integration of ODE systems from SymPy
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-sympy>=0.7.4.1:../../math/py-sympy

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
