# $NetBSD: Makefile,v 1.14 2006/11/01 22:22:04 brook1 Exp $
#

DISTNAME=		grass-${GRASS_VERSION}
CATEGORIES=		geography
MASTER_SITES=		http://grass.itc.it/grass60/source/

MAINTAINER=		brook@nmsu.edu
HOMEPAGE=		http://grass.itc.it/
COMMENT=		Open source geographical information system (GIS)

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake perl
USE_TOOLS+=		autoconf
USE_TOOLS+=		gm4
GNU_CONFIGURE=		yes

.include "options.mk"

PLIST_SRC+=		PLIST

CONFIGURE_ARGS+=	--without-opendwg
CONFIGURE_ARGS+=	--with-proj-share=${LOCALBASE}/share/proj

BUILDLINK_PASSTHRU_RPATHDIRS+=    ${GRASS_HOME}/lib

BUILD_TARGET=		default

pre-configure:
	cd ${WRKSRC} && autoconf || ${TRUE}

.include "Makefile.common"
.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../misc/proj/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
