# $NetBSD$

DISTNAME=	ndindex-1.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=n/ndindex/}

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://pypi.org/project/ndindex/
COMMENT=	Library for manipulating array indices.
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

USE_LANGUAGES+=	c
USE_LANGUAGES+=	c++

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=70.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
