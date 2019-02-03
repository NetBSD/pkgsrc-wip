# $NetBSD$

DISTNAME=	alg3dpy-0.16.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/c9/e6/25aab898cb3771afa510e2d0210692f7fed70fdd358bd8761267b7f234c2/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/saullocastro/alg3dpy
COMMENT=	3D Algebra in Python
LICENSE=	modified-bsd

#DEPENDS+=		${PYPKGPREFIX}-scipy>= :../../math/py-scipy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
