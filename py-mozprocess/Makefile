# $NetBSD$

DISTNAME=	mozprocess-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils www python
MASTER_SITES=	https://files.pythonhosted.org/packages/f6/81/5a9fec38e58d6c29a86867c801cad1b5022f0d14c961b68a729e737623a9/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://firefox-source-docs.mozilla.org/mozbase/mozprocess.html
COMMENT=	Mozilla-authored process handling
LICENSE=	mpl-2.0

DEPENDS+=	${PYPKGPREFIX}-mozinfo>=0:../../wip/py-mozinfo

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
