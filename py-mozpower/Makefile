# $NetBSD$

DISTNAME=	mozpower-1.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils www python
MASTER_SITES=	https://files.pythonhosted.org/packages/cb/66/f520bf19a73dd3c61ac51de1385ad36822bec3ecb1d9a1cdb46e10e58f14/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://firefox-source-docs.mozilla.org/mozbase/mozpower.html
COMMENT=	Mozilla-authored power usage measurement tools
LICENSE=	mpl-2.0

DEPENDS+=	#${PYPKGPREFIX}-mozlog>=6.0
DEPENDS+=	#${PYPKGPREFIX}-mozdevice>=4.0.0,<5

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
