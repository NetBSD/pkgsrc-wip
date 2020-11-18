# $NetBSD$

DISTNAME=	geopy-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/geopy/}

MAINTAINER=	lntl@disroot.org
HOMEPAGE=	https://github.com/geopy/geopy
COMMENT=	Python Geocoding Toolbox
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-geographiclib>=1.50:../../wip/py-geographiclib

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
