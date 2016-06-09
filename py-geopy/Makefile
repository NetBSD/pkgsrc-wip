# $NetBSD: Makefile,v 1.1 2014/03/21 17:57:56 jihbed Exp $

DISTNAME=	geopy-0.99
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	geography python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/geopy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://files.pythonhosted.org/packages/source/g/geopy/
COMMENT=	Python Geocoding Toolbox
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-requests-oauthlib>=0.4.0:../../security/py-requests-oauthlib

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
