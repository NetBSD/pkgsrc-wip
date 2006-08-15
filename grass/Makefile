# $NetBSD: Makefile,v 1.11 2006/08/15 16:42:45 brook1 Exp $
#

DISTNAME=		grass-6.0.2
CATEGORIES=		geography
MASTER_SITES=		http://grass.itc.it/grass60/source/

MAINTAINER=		brook@nmsu.edu
HOMEPAGE=		http://grass.itc.it/
COMMENT=		Open source geographical information system (GIS)

USE_LANGUAGES+=		c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake perl
USE_TOOLS+=		autoconf
USE_TOOLS+=		gm4
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=        --with-fftw=no

BUILDLINK_PASSTHRU_RPATHDIRS+=    ${GRASS_HOME}/lib

BUILD_TARGET=		default

GRASS_HOME?=		${PREFIX}/${PKGNAME}

pre-configure:
	cd ${WRKSRC} && autoconf || ${TRUE}

.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../misc/proj/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
