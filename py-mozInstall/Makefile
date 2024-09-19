# $NetBSD$

DISTNAME=	mozInstall-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel sysutils python
MASTER_SITES=	https://files.pythonhosted.org/packages/0f/13/a1560050203dbbff76930094e0dbdb8418a58c876a943b1327dcb4b18d5c/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://firefox-source-docs.mozilla.org/mozbase/mozinstall.html
COMMENT=	package for installing and uninstalling Mozilla applications
LICENSE=	mpl-2.0

DEPENDS+=	#${PYPKGPREFIX}-mozinfo>=0.7
DEPENDS+=	#${PYPKGPREFIX}-mozfile>=1.0
DEPENDS+=	${PYPKGPREFIX}-requests>=0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six
TEST_DEPENDS+=	#${PYPKGPREFIX}-mozprocess>=0.15

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
