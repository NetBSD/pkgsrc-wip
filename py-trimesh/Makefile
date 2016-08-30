# $NetBSD$

DISTNAME=	trimesh-1.11.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=t/trimesh/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://github.com/mikedh/trimesh
COMMENT=	Import, export, process, analyze and view triangular meshes
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-networkx>=1.10:../../math/py-networkx

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # py-networkx

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
