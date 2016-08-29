# $NetBSD$

DISTNAME=	fluids-0.1.50
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/fb/cb/b9a0c5ee64140bc0875c8da3711862695ccbdd24156007e5face040f19d4/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/CalebBell/fluids
COMMENT=	Fluid dynamics component of Chemical Engineering Design Library
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.18.0:../../math/py-scipy

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
