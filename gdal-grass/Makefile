# $NetBSD: Makefile,v 1.7 2010/01/17 12:03:25 thomasklausner Exp $
#

DISTNAME=		gdal-grass-1.3.1.2
PKGREVISION=		4
CATEGORIES=		geography
MASTER_SITES=		http://www.gdal.org/dl/

MAINTAINER=		brook@nmsu.edu
HOMEPAGE=		http://www.gdal.org/dl/
COMMENT=		Standalone GRASS 6 drivers for GDAL and OGR

.include "../../wip/grass/Makefile.common"

WRKSRC=			${WRKDIR}/gdal-grass-1.3.1
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gdal=${LOCALBASE}/bin/gdal-config
CONFIGURE_ARGS+=	--with-grass=${GRASS_HOME}
USE_LANGUAGES=		c++
BUILD_TARGET=		default

BUILDLINK_PASSTHRU_RPATHDIRS+=    ${GRASS_HOME}/lib

.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../wip/grass/buildlink3.mk"
.include "../../misc/proj/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
