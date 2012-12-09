# $NetBSD: Makefile,v 1.6 2012/12/09 16:15:35 lexort Exp $

DISTNAME=	libgeotiff-1.4.0
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://download.osgeo.org/geotiff/libgeotiff/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://trac.osgeo.org/geotiff/
COMMENT=	Library and tools for reading and writing GeoTIFF data
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../geography/proj/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
