# $NetBSD: Makefile,v 1.2 2013/02/24 18:05:31 asau Exp $
#

DISTNAME=	pyoperators-0.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	math
MASTER_SITES=	http://pypi.python.org/packages/source/p/pyoperators/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pchanial.github.com/pyoperators/
COMMENT=	Operators and solvers for high-performance computing


DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-fftw>=0.2:../../wip/py-fftw

PYDISTUTILSPKG=	yes

#PYTHON_VERSIONS_INCLUDE_3X= yes	# py-fftw doesn't support it yet

.include "../../devel/py-cython/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../math/py-numexpr/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
