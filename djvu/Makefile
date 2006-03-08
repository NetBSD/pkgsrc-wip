# $NetBSD: Makefile,v 1.5 2006/03/08 21:37:26 thomasklausner Exp $

DISTNAME=       djvulibre-3.5.16
CATEGORIES=     graphics
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=djvu/}

MAINTAINER=     oht@users.sourceforge.net
HOMEPAGE=       http://djvulibre.djvuzone.org/
COMMENT=        DjVu is a format & software platform for distributing doc's & images

CONFIGURE_ARGS+=         --enable-djview

CFLAG+=         -I${PREFIX}/include

GNU_CONFIGURE=  YES
USE_BUILDLINK3= YES
plugindir=     ${PREFIX}/lib/firefox/plugins

.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
