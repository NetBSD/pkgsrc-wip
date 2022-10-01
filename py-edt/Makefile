# $NetBSD$

DISTNAME=	edt-2.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=e/edt/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/seung-lab/euclidean-distance-transform-3d/
COMMENT=	Multi-Label Anisotropic Euclidean Distance Transform 3D
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++

BUILDLINK_API_DEPENDS.py-cython+=       ${PYPKGPREFIX}-cython>=0.12.1
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
