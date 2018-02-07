# $NetBSD: Makefile,v 1.1 2015/08/05 21:02:58 jihbed Exp $

DISTNAME=	Cartopy-0.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_PYPI:=C/Cartopy/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://scitools.org.uk/cartopy/docs/latest/
COMMENT=	Cartographic python library with matplotlib support for visualisation
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib

USE_LANGUAGES=	c c++

.include "../../devel/py-cython/buildlink3.mk"
.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
