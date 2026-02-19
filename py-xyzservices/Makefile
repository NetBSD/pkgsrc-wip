# $NetBSD$

DISTNAME=	xyzservices-2025.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	geography 
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xyzservices/}

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/geopandas/xyzservices
COMMENT=	Source of XYZ tiles providers
LICENSE=	modified-bsd

TOOL_DEPENDS+=       ${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
