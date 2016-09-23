# $NetBSD$

DISTNAME=	cesium-0.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/48/fa/d624ed95e48ab259eb0653c8d9b301aeee07715cc37c0d9f29dcb63d4ad2/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://cesium.ml/
COMMENT=	Machine Learning for Time Series Analysis Platform
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-cloudpickle>=0.2.1:../../devel/py-cloudpickle
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.18.1:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.18.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-dask>=0.11.0:../../wip/py-dask
DEPENDS+=	${PYPKGPREFIX}-gatspy>=0.3:../../wip/py-gatspy
DEPENDS+=	${PYPKGPREFIX}-scikit-learn>=0.18.0:../../wip/py-scikit-learn
DEPENDS+=	${PYPKGPREFIX}-toolz>=0.7.1:../../wip/py-toolz
DEPENDS+=	${PYPKGPREFIX}-xarray>=0.8.2:../../wip/py-xarray

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
