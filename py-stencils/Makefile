# $NetBSD$

DISTNAME=	pystencils-0.2.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	graphics python
MASTER_SITES=	https://files.pythonhosted.org/packages/7f/83/5fd619fd86963347d83c2f8100427e2b9febcf1cfa33f151b300cdc8e87d/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://i10git.cs.fau.de/pycodegen/pystencils/
COMMENT=	Speeding up stencil computations on CPUs and GPUs
LICENSE=	gnu-agpl-v3

DEPENDS+=	${PYPKGPREFIX}-appdirs>=1.4.4:../../devel/py-appdirs
DEPENDS+=	${PYPKGPREFIX}-joblib>=0.15.1:../../devel/py-joblib
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-sympy>=1.5.1:../../math/py-sympy
.include "../../mk/bsd.pkg.mk"
