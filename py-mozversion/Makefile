# $NetBSD$

DISTNAME=	mozversion-2.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	https://files.pythonhosted.org/packages/64/1f/d6a90f6da9b362642d6d4301202f20c8750322b2b365823b0362d4505821/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://wiki.mozilla.org/Auto-tools/Projects/Mozbase
COMMENT=	Library to get version information for applications
LICENSE=	mpl-2.0

DEPENDS+=	${PYPKGPREFIX}-mozlog>=6.0:../../wip/py-mozlog
DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
