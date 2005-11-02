# $NetBSD: Makefile,v 1.8 2005/11/02 18:00:13 thomasklausner Exp $

DISTNAME=		gdal-1.2.6
CATEGORIES=		geography
MASTER_SITES=		#empty
DISTFILES=		#empty

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://gdal.org/
COMMENT=		Translator library for raster geospatial data formats

DEPENDS+=       	gdal-lib-1.2.6:../../wip/gdal-lib
DEPENDS+=       	gdal-doc-1.2.6:../../wip/gdal-docs

NO_BUILD=		yes

do-install:
	@#empty

.include "../../wip/gdal-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
