# $NetBSD$

DISTNAME=	lightgbm-4.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lightgbm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/lightgbm/
COMMENT=	Gradient boosting (GBT, GBDT, GBRT, GBM or MART) framework
LICENSE=	mit

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
TOOL_DEPENDS+=	${PYPKGPREFIX}-scikit-build-core-[0-9]*:../../devel/py-scikit-build-core
# from pyproject.toml
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../math/py-scipy

USE_LANGUAGES=	c c++

#.include "../../devel/cmake/build.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
