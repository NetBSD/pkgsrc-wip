# $NetBSD: Makefile,v 1.6 2006/03/08 21:55:26 thomasklausner Exp $

DISTNAME=       djvulibre-3.5.16
CATEGORIES=     graphics
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=djvu/}

MAINTAINER=     oht@users.sourceforge.net
HOMEPAGE=       http://djvulibre.djvuzone.org/
COMMENT=        DjVu is a format & software platform for distributing doc's & images

CONFIGURE_ARGS+=         --enable-djview

GNU_CONFIGURE=  YES

.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
