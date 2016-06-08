# $NetBSD$

DISTNAME=	sunpy-0.6.1
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sunpy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.sunpy.org/
COMMENT=	Python for Solar Physicists
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-pandas>=0.16.2:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-astropy>=1.0.4:../../wip/py-astropy

.include "../../devel/py-cython/buildlink3.mk"
.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
