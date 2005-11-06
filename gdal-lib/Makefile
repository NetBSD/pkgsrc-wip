# $NetBSD: Makefile,v 1.8 2005/11/06 10:41:45 minskim Exp $
#

DISTNAME=		gdal-1.2.6
PKGNAME=		gdal-lib-1.2.6
CATEGORIES=		geography
MASTER_SITES=		http://gdal.org/dl/

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://gdal.org/
COMMENT=		Translator library for raster geospatial data formats

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

MAKEFILE=		GNUmakefile

CONFIGURE_ARGS+=	--with-pg
CONFIGURE_ARGS+=	--with-mysql=no
CONFIGURE_ARGS+=	--with-xerces
CONFIGURE_ARGS+=	--with-xerces-inc=${PREFIX}/include
CONFIGURE_ARGS+=	--with-xerces-lib="-L${PREFIX}/lib -lxerces-c"
CONFIGURE_ARGS+=	--with-geos
CONFIGURE_ARGS+=	--without-python

.include "../../misc/proj/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../geography/geos/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
