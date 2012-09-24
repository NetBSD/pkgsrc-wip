# $NetBSD: Makefile,v 1.9 2012/09/24 16:56:40 asau Exp $
#

DISTNAME=	awflwm-0.0
PKGREVISION=	2
CATEGORIES=	x11 wm
MASTER_SITES=	http://awflwm.berlios.de/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	low@ameba6.com
HOMEPAGE=	http://awflwm.berlios.de/
COMMENT=	Fork of the flwm project

PKG_DESTDIR_SUPPORT=	none

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	X_LIBS="-lGL"
MAKE_ENV+=	CXXFLAGS=${CXXFLAGS:M*:Q}
CXXFLAGS+=	-DFLTK_1_0_COMPAT
USE_LANGUAGES=	c c++

.include "../../x11/fltk/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
