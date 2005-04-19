# $NetBSD: Makefile,v 1.7 2005/04/19 20:50:29 daprice Exp $

DISTNAME=		gdal-1.2.6
CATEGORIES=		wip
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
