# $NetBSD$

DISTNAME=	fluids-1.0.26
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fluids/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/CalebBell/fluids
COMMENT=	Fluid dynamics component of Chemical Engineering Design Library
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-scipy>=1.6.0:../../math/py-scipy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.5.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
