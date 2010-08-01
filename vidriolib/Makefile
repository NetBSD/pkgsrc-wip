# $NetBSD: Makefile,v 1.3 2010/08/01 14:57:10 asau Exp $
#

DISTNAME=	vidriolib-0.1.20070718.0
CATEGORIES=	x11
MASTER_SITES=	http://vidrio.euler.es/vidriolib/bin/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ivaniclixx@gmail.com
HOMEPAGE=	http://vidrio.euler.es/vidriolib/bin/
COMMENT=	Viriolib is a windows, menus and so on development library

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++ fortran77
USE_TOOLS+=	pkg-config

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
