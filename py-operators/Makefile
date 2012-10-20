# $NetBSD: Makefile,v 1.1 2012/10/20 20:46:43 jihbed Exp $
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

PYTHON_VERSIONS_INCLUDE_3X= yes

.include "../../devel/py-cython/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../math/py-numexpr/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
