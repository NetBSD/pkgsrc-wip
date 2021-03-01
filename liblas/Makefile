# $NetBSD$

VERSION=        1.8.1
PKGNAME=	liblas-${VERSION}
PKGREVISION=	2
DISTNAME=	libLAS-${VERSION}
CATEGORIES=	geography
MASTER_SITES=	http://download.osgeo.org/liblas/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	thomas.orgis@uni-hamburg.de
HOMEPAGE=	http://www.liblas.org/
COMMENT=	LAS 1.0/1.1/1.2 ASPRS LiDAR data translation toolset
LICENSE=	2-clause-bsd

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	apps/liblas.pc.in

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../geography/libgeotiff/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
