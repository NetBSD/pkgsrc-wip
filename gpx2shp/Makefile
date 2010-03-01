# $NetBSD: Makefile,v 1.1.1.1 2010/03/01 14:50:21 uccwen Exp $
#

DISTNAME=	gpx2shp-0.69
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=gpx2shp/13458/}

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	http://gpx2shp.sourceforge.jp/
COMMENT=	Converts the GPS Exchange Format to ESRI/shape format
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

.include "../../misc/proj/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
