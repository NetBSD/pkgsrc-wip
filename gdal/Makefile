# $NetBSD: Makefile,v 1.4 2005/03/17 21:52:21 daprice Exp $

DISTNAME=		gdal-1.2.5
CATEGORIES=		wip
MASTER_SITES=		#empty
DISTFILES=		#empty

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://gdal.org/
COMMENT=		Translator library for raster geospatial data formats

DEPENDS+=       	gdal-1.2.5:../../wip/gdal-lib
DEPENDS+=       	gdal-doc-1.2.5:../../wip/gdal-docs

NO_BUILD=		yes

do-install:
	@#empty

.include "../../wip/gdal-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
