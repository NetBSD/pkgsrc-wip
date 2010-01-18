# $NetBSD: Makefile,v 1.17 2010/01/18 09:38:30 thomasklausner Exp $
#

DISTNAME=		qgis_1.0.2
PKGNAME=		qgis-1.0.2
PKGREVISION=		3
CATEGORIES=		geography
MASTER_SITES=		http://download.osgeo.org/qgis/src/
EXTRACT_SUFX=		.tar.gz

MAINTAINER=		brook@nmsu.edu
HOMEPAGE=		${MASTER_SITE_SOURCEFORGE:=qgis/}
COMMENT=		Geographic Information System (GIS)

.include "options.mk"

USE_PKGLOCALEDIR=       yes
USE_TOOLS+=		bison perl
USE_LANGUAGES+=		c c++ fortran
USE_CMAKE=		yes
USE_LIBTOOL=		yes
USE_X11=		yes

WRKSRC=			${WRKDIR}/${PKGNAME}

CMAKE_ARGS+=		-DCMAKE_INSTALL_PREFIX:PATH=${PREFIX}
CMAKE_ARGS+=		-DEXPAT_INCLUDE_DIR:PATH=${PREFIX}/include
CMAKE_ARGS+=		-DEXPAT_LIBRARY:FILEPATH=${PREFIX}/lib/libexpat.so
CMAKE_ARGS+=		-DGDAL_CONFIG_PREFER_PATH:STRING=${PREFIX}/bin
CMAKE_ARGS+=		-DGEOS_INCLUDE_DIR:PATH=${PREFIX}/geos/include
CMAKE_ARGS+=		-DGEOS_LIBRARY:FILEPATH=${PREFIX}/lib/libgeos.so
CMAKE_ARGS+=		-DPROJ_INCLUDE_DIR:PATH=${PREFIX}/include
CMAKE_ARGS+=		-DPROJ_LIBRARY:FILEPATH=/usr/pkg/lib/libproj.so
CMAKE_ARGS+=		-DQT_QMAKE_EXECUTABLE:FILEPATH=${PREFIX}/qt4/bin/qmake
CMAKE_ARGS+=		-DSQLITE3_INCLUDE_DIR:PATH=${PREFIX}/include
CMAKE_ARGS+=		-DSQLITE3_LIBRARY:FILEPATH=${PREFIX}/lib/libsqlite3.so

PLIST_VARS+=		grass python

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../misc/proj/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
