# $NetBSD$

DISTNAME=	TraceInv-0.0.23
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/T/t/}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=T/TraceInv/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://ameli.github.io/TraceInv
COMMENT=	Computes the trace of the inverse of matrix or linear matrix function
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3.2.2:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-seaborn>=0.9.0:../../graphics/py-seaborn
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.5.4:../../math/py-scipy

.include "../../devel/py-cython/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
