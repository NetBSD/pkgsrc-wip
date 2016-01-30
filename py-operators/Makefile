# $NetBSD$

DISTNAME=	pyoperators-0.13.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyoperators/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pchanial.github.com/pyoperators/
COMMENT=	Operators and solvers for high-performance computing

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-fftw>=0.2:../../math/py-fftw

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # py-fftw
EGG_NAME=	pyoperators-0.13

.include "../../devel/py-cython/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../math/py-numexpr/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
