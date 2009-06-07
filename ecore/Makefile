# $NetBSD: Makefile,v 1.27 2009/06/07 21:27:34 jsonn Exp $
#

DISTNAME=	ecore-0.9.9.060
CATEGORIES=	x11
MASTER_SITES=	http://download.enlightenment.org/snapshots/2009-04-22/

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Event Abstraction and Modular Convenience Library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

CONFIGURE_ARGS+=	--disable-openssl \
		 	--disable-ecore-directfb \
			--enable-ecore-desktop \
			--disable-ecore-evas-sdl

.include "../../devel/eet/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/evas-buffer/buildlink3.mk"
.include "../../graphics/evas-software-x11/buildlink3.mk"
.include "../../graphics/evas-xrender-x11/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
