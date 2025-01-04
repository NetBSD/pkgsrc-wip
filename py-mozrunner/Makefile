# $NetBSD$

DISTNAME=	mozrunner-8.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	category python
MASTER_SITES=	https://files.pythonhosted.org/packages/25/d8/ca51dbc412c836dafae2d9173f595aaf6d2739c8fd508dbf6e9341b60968/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://wiki.mozilla.org/Auto-tools/Projects/Mozbase
COMMENT=	Reliable start/stop/configuration of Mozilla Applications (Firefox, Thunderbird, etc.)
#LICENSE=	MPL 2.0 # TODO: from setup.py; needs to be adjusted

DEPENDS+=	${PYPKGPREFIX}-mozdevice>=4.0.0:../../wip/py-mozdevice
DEPENDS+=	${PYPKGPREFIX}-mozfile>=1.2:../../wip/py-mozfile
DEPENDS+=	${PYPKGPREFIX}-mozinfo>=0.7:../../wip/py-mozinfo
DEPENDS+=	${PYPKGPREFIX}-mozlog>=6.0:../../wip/py-mozlog
DEPENDS+=	${PYPKGPREFIX}-mozprocess>=1.2.0:../../wip/py-mozprocess
DEPENDS+=	${PYPKGPREFIX}-mozprofile>=2.3.0:../../wip/py-mozprofile
DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
