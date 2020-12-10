# $NetBSD$

DISTNAME=	kineticlib-1.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/kineticlib/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/Kunstmord/kineticlib
COMMENT=	Library for kinetic theory calculations in the multi-temperature
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-scipy>=1.2.3:../../math/py-scipy

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
