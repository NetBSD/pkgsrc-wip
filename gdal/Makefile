# $NetBSD: Makefile,v 1.9 2006/03/23 00:11:55 mchittur Exp $

DISTNAME=		gdal-1.3.1
CATEGORIES=		geography
MASTER_SITES=		#empty
DISTFILES=		#empty

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://gdal.org/
COMMENT=		Translator library for raster geospatial data formats

DEPENDS+=       	gdal-lib-1.3.1:../../wip/gdal-lib
DEPENDS+=       	gdal-doc-1.3.1:../../wip/gdal-docs

NO_BUILD=		yes

do-install:
	@#empty

.include "../../wip/gdal-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
