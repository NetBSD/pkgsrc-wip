# $NetBSD$

DISTNAME=	c-lasso-1.0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/c-lasso/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/Leo-Simpson/CLasso
COMMENT=	Algorithms for constrained Lasso problems
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE+=	27

DEPENDS+=	${PYPKGPREFIX}-h5py>=0:../../devel/py-h5py
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=0:../../graphics/py-matplotlib
#DEPENDS+=	${PYPKGPREFIX}-scipy>=0:../../math/py-scipy

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
