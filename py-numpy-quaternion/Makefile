# $NetBSD$

DISTNAME=	numpy-quaternion-2022.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/numpy-quaternion/}

MAINTAINER=	jihbed.rsearch@gmail.com
HOMEPAGE=	https://github.com/moble/quaternion
COMMENT=	Add a quaternion dtype to NumPy
LICENSE=	mit

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.13

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
