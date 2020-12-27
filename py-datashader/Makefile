# $NetBSD$

DISTNAME=	datashader-0.11.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/datashader/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://datashader.org
COMMENT=	Data visualization toolchain based on aggregating into a grid
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-dask>=0.18.0:../../wip/py-dask
DEPENDS+=	${PYPKGPREFIX}-toolz>=0.7.4:../../devel/py-toolz
DEPENDS+=	${PYPKGPREFIX}-datashape>=0.5.1:../../wip/py-datashape
DEPENDS+=	${PYPKGPREFIX}-numba>=0.37.0:../../math/py-numba
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.24.1:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-Pillow>=3.1.1:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-xarray>=0.9.6:../../math/py-xarray
DEPENDS+=	${PYPKGPREFIX}-colorcet>=0.9.0:../../wip/py-colorcet
DEPENDS+=	${PYPKGPREFIX}-param>=1.6.0:../../wip/py-param
DEPENDS+=	${PYPKGPREFIX}-ct>=0.4.6:../../wip/py-ct
DEPENDS+=	${PYPKGPREFIX}-bokeh>=0:../../wip/py-bokeh
DEPENDS+=	${PYPKGPREFIX}-scipy>=0:../../math/py-scipy
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.9.3:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-benchmark>=3.0.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.10.1:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-codecov>=2.0.15:../../wip/py-codecov
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8>=3.8.4:../../devel/py-flake8

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>=1.7
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
