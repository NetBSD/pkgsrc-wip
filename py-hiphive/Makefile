# $NetBSD$

DISTNAME=	hiphive-0.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/4b/de/5c91cb7c24167456f0284e91c8f98a8d21cc0bb5d4a747ceb19708be3559/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://hiphive.materialsmodeling.org/
COMMENT=	High-order force constants for the masses
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-h5py>=2.9.0:../../devel/py-h5py
DEPENDS+=	${PYPKGPREFIX}-numba>=0.50.1:../../math/py-numba
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.4.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-scikit-learn>=0.22.1:../../math/py-scikit-learn
DEPENDS+=	${PYPKGPREFIX}-sympy>=1.5.1:../../math/py-sympy

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.10
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
