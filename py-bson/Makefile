# $NetBSD$

DISTNAME=	bson-0.5.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bson/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/py-bson/bson
COMMENT=	BSON codec for Python
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.4.0:../../time/py-dateutil

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
