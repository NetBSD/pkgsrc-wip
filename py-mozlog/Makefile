# $NetBSD$

DISTNAME=	mozlog-6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	https://files.pythonhosted.org/packages/08/d8/396d951ca01222647569ef9064700a03ea99852c540a07e0828e25e200d0/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://wiki.mozilla.org/Auto-tools/Projects/Mozbase
COMMENT=	Robust log handling specialized for logging in the Mozilla universe
LICENSE=	mpl-2.0

DEPENDS+=	${PYPKGPREFIX}-blessings>=1.3:../../devel/py-blessings
DEPENDS+=	${PYPKGPREFIX}-mozterm>=1.0.0:../../wip/py-mozterm
DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six

TEST_DEPENDS+=	${PYPKGPREFIX}-mozfile>=2.1.0:../../wip/py-mozfile

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
