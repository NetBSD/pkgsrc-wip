# $NetBSD$

DISTNAME=	CASPy3-1.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/7d/32/e1e71579bf24178638eef41454f3d75472fb782770dcbdd04bad2bc81ce3/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/Secozzi/CASPy
COMMENT=	GUI and a CLI to a symbolic computation using SymPy
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-click>=7.1.2:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-sympy>=1.5.1:../../math/py-sympy

USE_LANGUAGES=	# none

.include "../../x11/py-qt5/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
