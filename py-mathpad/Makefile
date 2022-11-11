# $NetBSD$

DISTNAME=	mathpad-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mathpad/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/CallumJHays/mathpad
COMMENT=	Interface to Sympy for solving physics, engineering and maths problems
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-plotly>=5.3.1:../../wip/py-plotly
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.7.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-sympy>=1.8:../../math/py-sympy
DEPENDS+=	${PYPKGPREFIX}-tqdm>=4.62.3:../../misc/py-tqdm
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.0.0:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.20
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
