# $NetBSD: Makefile,v 1.10 2006/05/02 21:03:05 thomasklausner Exp $
#

DISTNAME=		grass-6.0.0
CATEGORIES=		geography
MASTER_SITES=		http://grass.itc.it/grass60/source/

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://grass.itc.it/
COMMENT=		Open source, free software geographical information system (GIS)

USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake perl
GNU_CONFIGURE=		YES

BUILD_TARGET=		default

CONFIGURE_ARGS+=        --with-fftw=no

.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../misc/proj/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
