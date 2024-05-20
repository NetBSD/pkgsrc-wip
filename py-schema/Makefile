# $NetBSD$

DISTNAME=	schema-0.7.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/schema/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/keleshev/schema
COMMENT=	Simple data validation library
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
