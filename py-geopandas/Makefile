# $NetBSD$

DISTNAME=	geopandas-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	geography python
MASTER_SITES=   ${MASTER_SITE_PYPI:=g/geopandas/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://geopandas.org/
COMMENT=	Geographic pandas extensions
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-pandas>=0.25.3:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-py-fiona>=1.6.0:../../wip/py-fiona
DEPENDS+=	${PYPKGPREFIX}-shapely>=1.7.0:../../wip/py-shapely


.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
