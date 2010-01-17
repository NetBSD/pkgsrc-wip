# $NetBSD: Makefile,v 1.18 2010/01/17 12:03:25 thomasklausner Exp $

DISTNAME=		gdal-1.3.1
PKGREVISION=		4
CATEGORIES=		geography
MASTER_SITES=		#empty
DISTFILES=		#empty

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://gdal.org/
COMMENT=		Translator library for raster geospatial data formats

DEPENDS+=	gdal-lib>=1.3.1:../../geography/gdal-lib
DEPENDS+=	gdal-docs-1.3.1{,nb*}:../../wip/gdal-docs

NO_BUILD=		yes

do-install:
	@#empty

.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
