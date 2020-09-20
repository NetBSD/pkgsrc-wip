# $NetBSD$

DISTNAME=	plottr-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	https://files.pythonhosted.org/packages/41/d5/36bd15aa3fbd82273c0b2ce3f65a281d0c1f06126e389a917f3cd5be8787/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/toolsforexperiments/plottr
COMMENT=	Tool for live plotting and processing data
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-h5py>=1.9.0:../../devel/py-h5py
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=1.9.0:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-qtgraph>=1.9.0:../../graphics/py-qtgraph
DEPENDS+=	${PYPKGPREFIX}-lmfit>=1.0.1:../../math/py-lmfit
DEPENDS+=	${PYPKGPREFIX}-pandas>=1.9.0:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-xarray>=1.9.0:../../math/py-xarray

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
