# $NetBSD$

DISTNAME=	poppy-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/5a/0f/3719002f4581effcbe8a792ce2405e3bdb6cd41d01bf98dddfa17905885d/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pythonhosted.org/poppy/
COMMENT=	Physical optics propagation for optical simulations
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.17.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-astropy>=1.1.1:../../wip/py-astropy
DEPENDS+=	${PYPKGPREFIX}-enum>=0.4.6:../../wip/py-enum

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
