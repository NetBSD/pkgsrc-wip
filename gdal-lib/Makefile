# $NetBSD: Makefile,v 1.1.1.1 2005/03/17 21:53:23 daprice Exp $
#

DISTNAME=		gdal-1.2.5
CATEGORIES=		wip
MASTER_SITES=		http://gdal.org/dl/

MAINTAINER=		pshah@nmsu.edu
HOMEPAGE=		http://gdal.org/
COMMENT=		Translator library for raster geospatial data formats

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

MAKEFILE=		GNUmakefile

CONFIGURE_ARGS+=	--with-pg
CONFIGURE_ARGS+=	--with-mysql=no
CONFIGURE_ARGS+=	--with-xerces
CONFIGURE_ARGS+=	--with-xerces-inc=${PREFIX}/include
CONFIGURE_ARGS+=	--with-xerces-lib="-L${PREFIX}/lib -lxerces-c"
CONFIGURE_ARGS+=	--with-geos

.include "../../misc/proj/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../wip/geos2/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
