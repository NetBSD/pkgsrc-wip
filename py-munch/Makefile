# $NetBSD$

DISTNAME=	munch-2.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/munch/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/Infinidat/munch
COMMENT=	Dot-accessible dictionary (a la JavaScript objects)
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-pbr>=3.0:../../devel/py-pbr
DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
