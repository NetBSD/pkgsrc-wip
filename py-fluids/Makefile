# $NetBSD$

DISTNAME=	fluids-0.1.51
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/1f/53/be2696d0085bc16095b3a50f2e431363e2e1ccdcc76b7fa8dacfdd808103/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/CalebBell/fluids
COMMENT=	Fluid dynamics component of Chemical Engineering Design Library
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.18.0:../../math/py-scipy

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
