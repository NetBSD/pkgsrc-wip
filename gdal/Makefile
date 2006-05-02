# $NetBSD: Makefile,v 1.10 2006/05/02 21:03:05 thomasklausner Exp $

DISTNAME=		gdal-1.3.1
CATEGORIES=		geography
MASTER_SITES=		#empty
DISTFILES=		#empty

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://gdal.org/
COMMENT=		Translator library for raster geospatial data formats

DEPENDS+=       	gdal-lib-1.3.1:../../geography/gdal-lib
DEPENDS+=       	gdal-doc-1.3.1:../../wip/gdal-docs

NO_BUILD=		yes

do-install:
	@#empty

.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
