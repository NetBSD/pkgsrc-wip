# $NetBSD: Makefile,v 1.2 2005/04/11 21:13:46 tvierling Exp $

DISTNAME=	libgeotiff-1.2.2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.remotesensing.org/pub/geotiff/libgeotiff/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://www.remotesensing.org/geotiff/geotiff.html
COMMENT=	Library and tools for reading and writing GeoTIFF data

GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

.include "../../graphics/tiff/buildlink3.mk"
.include "../../misc/proj/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
