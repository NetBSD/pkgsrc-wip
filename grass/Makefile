# $NetBSD: Makefile,v 1.6 2005/06/10 20:34:32 thomasklausner Exp $
#

DISTNAME=		grass-6.0.0
CATEGORIES=		wip
MASTER_SITES=		http://grass.itc.it/grass60/source/

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://grass.itc.it/
COMMENT=		Open source, free software geographical information system (GIS)

USE_PERL5=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_X11=		YES
USE_TOOLS+=		gmake

BUILD_TARGET=		default

CONFIGURE_ARGS+=        --with-fftw=no

.include "../../x11/tk/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../misc/proj/buildlink3.mk"
.include "../../wip/gdal-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
