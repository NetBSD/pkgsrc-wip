# $NetBSD: Makefile,v 1.24 2008/11/19 01:12:09 jsonn Exp $
#

DISTNAME=	ecore-0.9.9.050
CATEGORIES=	x11
MASTER_SITES=	http://download.enlightenment.org/snapshots/2008-09-25/

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
.include "../../wip/evas/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
#.include "../../devel/SDL/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
