# $NetBSD: Makefile,v 1.1 2005/03/14 15:10:29 thomasklausner Exp $

DISTNAME=	djvulibre-3.5.14
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=djvu/}

MAINTAINER=	oht@users.sourceforge.net
HOMEPAGE=   	http://djvulibre.djvuzone.org/
COMMENT=	DjVu is a format & software platform for distributing doc's & images

CONFIGURE_ARGS+=         --enable-djview

CFLAG+=		-I${PREFIX}/include

GNU_CONFIGURE=  YES
USE_BUILDLINK3= YES

.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
