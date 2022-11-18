# $NetBSD$

DISTNAME=	awkward-1.10.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=a/awkward/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/scikit-hep/awkward-1.0
COMMENT=	Manipulate JSON-like data with NumPy-like idioms
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-packaging>=21.3:../../devel/py-importlib-resources
DEPENDS+=	${PYPKGPREFIX}-packaging>=21.3:../../devel/py-packaging

#USE_CMAKE=	yes
USE_LANGUAGES=	c++

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.8
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
