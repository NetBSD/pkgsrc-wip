# $NetBSD$

DISTNAME=	stravalib-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=s/stravalib/}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://github.com/stravalib/stravalib
COMMENT=	Tools for accessing and downloading Strava data
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

TOOL_DEPENDS+=	${PYPKGPREFIX}-distlib:../../devel/py-distlib

DEPENDS+=	${PYPKGPREFIX}-pint:../../wip/py-pint
DEPENDS+=	${PYPKGPREFIX}-pytz:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-arrow:../../time/py-arrow
DEPENDS+=	${PYPKGPREFIX}-requests>=2.0<3.0:../../devel/py-requests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
