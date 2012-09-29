# $NetBSD: Makefile,v 1.20 2012/09/29 00:50:34 asau Exp $

DISTNAME=		gdal-1.3.1
PKGREVISION=		5
CATEGORIES=		geography
MASTER_SITES=		#empty
DISTFILES=		#empty

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://gdal.org/
COMMENT=		Translator library for raster geospatial data formats

DEPENDS+=	gdal-lib>=1.3.1:../../geography/gdal-lib
DEPENDS+=	gdal-docs-1.3.1{,nb*}:../../wip/gdal-docs

PKG_DESTDIR_SUPPORT=	none

NO_BUILD=		yes

do-install:
	@#empty

.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
