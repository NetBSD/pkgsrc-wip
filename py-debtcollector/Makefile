# $NetBSD$

DISTNAME=	debtcollector-2.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/debtcollector/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://docs.openstack.org/debtcollector/latest/
COMMENT=	Python deprecation patterns and strategiest you technical debt
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	27 36

BUILD_DEPENDS+=	${PYPKGPREFIX}-pbr>=2.0.0:../../devel/py-pbr

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
