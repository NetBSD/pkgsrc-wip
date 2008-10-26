# $NetBSD: Makefile,v 1.23 2008/10/26 07:41:46 minskim Exp $
#

DISTNAME=	ecore-0.9.9.050
CATEGORIES=	x11
MASTER_SITES=	http://download.enlightenment.org/snapshots/2008-09-25/

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Event Abstraction and Modular Convenience Library

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
