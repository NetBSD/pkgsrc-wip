# $NetBSD: Makefile,v 1.7 2005/06/12 23:51:22 kristerw Exp $
#

DISTNAME=		mapserver-4.4.2
CATEGORIES=		wip
MASTER_SITES=		http://cvs.gis.umn.edu/dist/

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://mapserver.gis.umn.edu/
COMMENT=		Environment for building spatially enabled Internet apps

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-curl-config		\
			--with-tiff			\
			--with-pdf			\
			--with-php=${PREFIX}		\
			--with-proj			\
			--with-ogr			\
			--with-gdal			\
			--with-postgis			\
			--with-libiconv			\
			--with-zlib			\
			--with-gd=${PREFIX}		\
			--with-tiff			\
			--with-xpm=${PREFIX}/lib	\
			--with-jpeg			\
			--with-png			\
			--with-geos			\
			--with-wfs			\
			--with-wcs			\
			--with-wmsclient		\
			--with-wfsclient

CFLAGS+=		-I${PREFIX}/include/php/main
CFLAGS+=		-I${PREFIX}/include/php/Zend
CFLAGS+=		-I${PREFIX}/include/php/TSRM
CFLAGS+=		-I${PREFIX}/include/php/regex
CFLAGS+=		-I${PREFIX}/include/php
CFLAGS+=		-I${WRKSRC}

PKG_OPTIONS_VAR=	PKG_OPTIONS.mapserver
PKG_SUPPORTED_OPTIONS=	postgresql73 postgresql74 postgresql80
PKG_SUGGESTED_OPTIONS=	postgresql80

.include "../../mk/bsd.options.mk"

do-install:
	${INSTALL_DATA} ${WRKSRC}/libmap.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/map.h ${PREFIX}/include
	${INSTALL_PROGRAM} ${WRKSRC}/mapserv ${PREFIX}/libexec/cgi-bin
.for PROGRAM in shp2img shp2pdf legend shptree shptreevis	\
	shptreetst scalebar sortshp
	${INSTALL_PROGRAM} ${WRKSRC}/${PROGRAM} ${PREFIX}/bin
.endfor

.include "../../www/curl/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../print/pdflib/buildlink3.mk"
.include "../../www/php4/buildlink3.mk"
.include "../../misc/proj/buildlink3.mk"
.include "../../wip/gdal-lib/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk" # this must come before the next line
.include "../../wip/postgresql${PGSQL_VERSION}-postgis/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../wip/geos/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
