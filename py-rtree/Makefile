# $NetBSD$

DISTNAME=	Rtree-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	geography python
MASTER_SITES=	${MASTER_SITE_PYPI:=R/Rtree/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/Toblerity/rtree
COMMENT=	R-Tree spatial index for Python GIS
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	38

TOOL_DEPENDS+=     ${PYPKGPREFIX}-setuptools>=70.0:../../devel/py-setuptools
TOOL_DEPENDS+=  ${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
