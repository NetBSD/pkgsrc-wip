# $NetBSD: Makefile,v 1.1.1.1 2005/03/17 21:04:04 daprice Exp $
#

DISTNAME=		qgis-0.6.0
CATEGORIES=		wip
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=qgis/}

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://www.qgis.org/
COMMENT=		QuantumGIS supports vector, raster and DB format data

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

CONFIGURE_ARGS+=	--with-grass=${PREFIX}/grass-6.0.0

pre-build:
	${SED} -e 's:@QTBINDIR@:${QTDIR}/bin:g' ${WRKSRC}/create_qm_files.sh > ${WRKSRC}/create_qm_files.sh.tmp
	${MV} ${WRKSRC}/create_qm_files.sh.tmp ${WRKSRC}/create_qm_files.sh
	${CHMOD} 755 ${WRKSRC}/create_qm_files.sh

.include "../../wip/grass/buildlink3.mk"
.include "../../wip/gdal/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
