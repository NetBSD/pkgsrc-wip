# $NetBSD$

DISTNAME=	hydrointerp-1.0.15
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://files.pythonhosted.org/packages/57/eb/13511527e0ddb891dd1e4f22d657fac93e00f07508044f339a975f8f3134/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/mullenkamp/hydrointerp
COMMENT=	Function for interpolating hydrologic features
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-pandas>=0.23.4:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.1.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-fiona>=1.1.0:../../wip/py-fiona
DEPENDS+=	${PYPKGPREFIX}-proj>=1.1.0:../../wip/py-proj
DEPENDS+=	${PYPKGPREFIX}-xarray-[0-9]*:../../math/py-xarray

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
