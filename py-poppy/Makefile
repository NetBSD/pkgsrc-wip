# $NetBSD$

DISTNAME=	poppy-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/poppy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pythonhosted.org/poppy/
COMMENT=	Physical optics propagation for optical simulations
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-astropy>=1.1.1:../../wip/py-astropy
DEPENDS+=	${PYPKGPREFIX}-enum>=0.4.6:../../devel/py-enum
DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.17.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
