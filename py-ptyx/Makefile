# $NetBSD$

DISTNAME=	ptyx-20.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	print python
MASTER_SITES=	https://files.pythonhosted.org/packages/c0/21/5cc7d642f2972c53978c9217cef1edbdfeec004a054fc9731fcab0fe370c/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/wxgeo/ptyx
COMMENT=	pTyX is a python precompiler for LaTeX
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-sympy>=1.5.1:../../math/py-sympy
DEPENDS+=	${PYPKGPREFIX}-Pillow>=6.2.2:../../graphics/py-Pillow

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
