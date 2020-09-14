# $NetBSD$

DISTNAME=	APScheduler-3.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	category python
MASTER_SITES=	https://files.pythonhosted.org/packages/89/3d/f65972547c5aa533276ada2bea3c2ef51bb4c4de55b67a66129c111b89ad/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/agronholm/apscheduler
COMMENT=	In-process task scheduler with Cron-like capabilities
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-tzlocal>=2.1:../../time/py-tzlocal

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
