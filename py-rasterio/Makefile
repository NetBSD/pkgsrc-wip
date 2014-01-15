# $NetBSD: Makefile,v 1.1 2014/01/15 21:00:45 jihbed Exp $

DISTNAME=	rasterio-0.4
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/source/r/rasterio/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pypi.python.org/packages/source/r/rasterio/
COMMENT=	Fast and direct raster I/O for Python programmers who use Numpy
LICENSE=	modified-bsd

.include "../../devel/py-cython/buildlink3.mk"
.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
