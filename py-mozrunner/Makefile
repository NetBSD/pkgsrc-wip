# $NetBSD$

DISTNAME=	mozrunner-8.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	category python
MASTER_SITES=	https://files.pythonhosted.org/packages/25/85/85289f9df6319328561bbccd344ff32a3c4ffbc2d3b94097d3d760d933a1/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://wiki.mozilla.org/Auto-tools/Projects/Mozbase
COMMENT=	Reliable start/stop/configuration of Mozilla Applications (Firefox, Thunderbird, etc.)
#LICENSE=	MPL 2.0 # TODO: from setup.py; needs to be adjusted

DEPENDS+=	# TODO: mozdevice>=4.0.0,<5
DEPENDS+=	# TODO: mozfile>=1.2
DEPENDS+=	# TODO: mozinfo>=0.7,<2
DEPENDS+=	# TODO: mozlog>=6.0
DEPENDS+=	# TODO: mozprocess>=1.2.0,<2
DEPENDS+=	# TODO: mozprofile~=2.3>=0
DEPENDS+=	py-six>=1.10.0,<2:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
