# $NetBSD$

DISTNAME=	happy_control-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/happy_control/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/ViktorRusakov/happy-control
COMMENT=	Nonlinear Algebraic Approximation in Control systems
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-antlr4-[0-9]*:../../textproc/py-antlr4
DEPENDS+=	${PYPKGPREFIX}-cython>=0.29.14:../../devel/py-cython
DEPENDS+=	${PYPKGPREFIX}-sympy>=1.5.1:../../math/py-sympy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.18.1
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
