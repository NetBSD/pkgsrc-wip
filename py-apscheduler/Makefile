# $NetBSD$

DISTNAME=	apscheduler-3.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/apscheduler/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/agronholm/apscheduler
COMMENT=	In-process task scheduler with Cron-like capabilities
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm

DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-tzlocal>=3.0:../../time/py-tzlocal

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
