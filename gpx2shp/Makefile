# $NetBSD: Makefile,v 1.3 2010/03/14 16:32:22 thomasklausner Exp $
#

DISTNAME=	gpx2shp-0.69
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=gpx2shp/13458/}

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	http://gpx2shp.sourceforge.jp/
COMMENT=	Converts GPX to ESRI shapefile format
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

.include "../../geography/proj/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
