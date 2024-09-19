# $NetBSD$

DISTNAME=	geocoder-1.38.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	geography python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/geocoder/}

MAINTAINER=	lntl@disroot.org
HOMEPAGE=	https://github.com/DenisCarriere/geocoder
COMMENT=	Simple and consistent geocoding library
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-requests>=0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-ratelim>=0:../../wip/py-ratelim
DEPENDS+=	${PYPKGPREFIX}-click>=0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-six>=0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-future>=0:../../devel/py-future

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
