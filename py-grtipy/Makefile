# $NetBSD$

DISTNAME=	GrTiPy-0.1.0
PKGNAME=	${PYPKGPREFIX}-grtipy-0.1.0
CATEGORIES=	math
MASTER_SITES=	https://files.pythonhosted.org/packages/e3/1d/1eb17b9945fbc16c414983d8dd920b8fd2e7266df332b054922de762c801/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://files.pythonhosted.org/packages/e3/1d/1eb17b9945fbc16c414983d8dd920b8fd2e7266df332b054922de762c801/
COMMENT=	General Relativity toolbox in python
LICENSE=	modified-bsd


DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3.2.2:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.4.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-sympy>=1.5.1:../../math/py-sympy

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
