# $NetBSD: Makefile,v 1.4 2015/05/30 17:42:10 jihbed Exp $

DISTNAME=	pyoperators-0.13.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/p/pyoperators/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pchanial.github.com/pyoperators/
COMMENT=	Operators and solvers for high-performance computing
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-fftw>=0.2:../../math/py-fftw

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-fftw
EGG_NAME=	pyoperators-0.13

.include "../../devel/py-cython/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../math/py-numexpr/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
