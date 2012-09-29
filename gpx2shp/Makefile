# $NetBSD: Makefile,v 1.4 2012/09/29 00:50:40 asau Exp $
#

DISTNAME=	gpx2shp-0.69
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=gpx2shp/13458/}

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	http://gpx2shp.sourceforge.jp/
COMMENT=	Converts GPX to ESRI shapefile format
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

.include "../../geography/proj/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
