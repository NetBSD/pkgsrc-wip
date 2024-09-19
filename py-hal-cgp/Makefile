# $NetBSD$

DISTNAME=	hal-cgp-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/37/ab/33a2209ffe1477ced75ac5a40ad8b5cbeeca532e60e91b3a6496964e2b60/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/Happy-Algorithms-League/hal-cgp
COMMENT=	Cartesian Genetic Programming in pure Python
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-sympy>=1.5.1:../../math/py-sympy

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>1.11.3
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
