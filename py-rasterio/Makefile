# $NetBSD: Makefile,v 1.4 2015/03/14 18:42:49 lexort Exp $

DISTNAME=	rasterio-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rasterio/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://files.pythonhosted.org/packages/source/r/rasterio/
COMMENT=	Fast and direct raster I/O for Python programmers who use Numpy
LICENSE=	modified-bsd

.include "../../devel/py-cython/buildlink3.mk"
.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
