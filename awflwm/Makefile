# $NetBSD: Makefile,v 1.5 2005/11/28 00:27:23 rillig Exp $
#

DISTNAME=	awflwm-0.0
PKGREVISION=	1
CATEGORIES=	x11 wm
MASTER_SITES=	http://awflwm.berlios.de/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	low@ameba6.com
HOMEPAGE=	http://awflwm.berlios.de/
COMMENT=	Fork of the flwm project

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	X_LIBS="-lGL"
MAKE_ENV+=	CXXFLAGS=${CXXFLAGS:M*:Q}
CXXFLAGS+=	-DFLTK_1_0_COMPAT

.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
