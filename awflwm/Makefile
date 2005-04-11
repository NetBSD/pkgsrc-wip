# $NetBSD: Makefile,v 1.2 2005/04/11 21:10:04 tvierling Exp $
#

DISTNAME=	awflwm-0.0
PKGREVISION=	1
CATEGORIES=	x11 wm
MASTER_SITES=	http://awflwm.berlios.de/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	low@ameba6.com
HOMEPAGE=	http://awflwm.berlios.de/
COMMENT=	Fork of the flwm project

USE_X11=	# defined

GNU_CONFIGURE=	# defined
CONFIGURE_ENV+=	X_LIBS="-lGL"
MAKE_ENV+=	CXXFLAGS="${CXXFLAGS}"
CXXFLAGS+=	-DFLTK_1_0_COMPAT

.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
