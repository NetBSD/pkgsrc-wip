# $NetBSD: Makefile,v 1.1.1.1 2005/02/25 20:26:56 daprice Exp $
#

DISTNAME=		gdal-1.1.9
CATEGORIES=		geography
MASTER_SITES=           http://dl1.maptools.org/dl/gdal/ \
			ftp://ftp.remotesensing.org/pub/gdal/

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://www.remotesensing.org/gdal/
COMMENT=		Translator library for raster geospatial data formats

DEPENDS+=		doxygen>=1.2.18:../../devel/doxygen

USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make

WRKSRC=			${WRKDIR}/gdal-1.1.9

CONFIGURE_ARGS+=	--with-grass=no

CFLAGS+=		-I${PREFIX}/include/postgresql
LIBS+=			-L${PREFIX}/lib

MAKEFILE=		GNUmakefile

do-build:
	cd ${WRKSRC} && ${GMAKE} -f ${MAKEFILE}

do-install:
	cd ${WRKSRC} && ${GMAKE} -f ${MAKEFILE} ${INSTALL}

.include "../../databases/postgresql74-lib/buildlink3.mk"
.include "../../lang/python15/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
