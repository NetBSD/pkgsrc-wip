# $NetBSD: Makefile,v 1.9 2006/06/30 22:00:39 thomasklausner Exp $

DISTNAME=       djvulibre-3.5.17
CATEGORIES=     graphics
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=djvu/}

MAINTAINER=     oht@users.sourceforge.net
HOMEPAGE=       http://djvulibre.djvuzone.org/
COMMENT=        Format and software platform for distributing documents and images

CONFIGURE_ARGS+=         --enable-djview
GNU_CONFIGURE=  YES
USE_LANGUAGES=	c c++

.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
