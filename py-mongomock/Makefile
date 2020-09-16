# $NetBSD$

DISTNAME=	mongomock-3.20.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/7b/2d/7e83e435d1bc5a1a8f6e06f5e4f425aeb38a52a35e9539e7d2da0e528f2a/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://files.pythonhosted.org/packages/7b/2d/7e83e435d1bc5a1a8f6e06f5e4f425aeb38a52a35e9539e7d2da0e528f2a/
COMMENT=	Fake pymongo stub for testing simple MongoDB-dependent code
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-bson>=0.5.10:../../devel/py-bson
DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six
BUILD_DEPENDS+=	${PYPKGPREFIX}-pbr>=5.4.5:../../devel/py-pbr


USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
