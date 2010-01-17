# $NetBSD: Makefile,v 1.9 2010/01/17 12:03:28 thomasklausner Exp $
#

DISTNAME=		libopenmodeller-0.3.3
PKGREVISION=		4
CATEGORIES=		geography
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=openmodeller/}

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://openmodeller.sourceforge.net/
COMMENT=		Spatial distribution modelling library

USE_PKGLOCALEDIR=	YES
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		YES

.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../geography/geos/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
