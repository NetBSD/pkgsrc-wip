# $NetBSD: Makefile,v 1.3 2012/09/29 00:50:41 asau Exp $
#

DISTNAME=	gtkglextmm-1.2.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkglext/}

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://gtkglext.sourceforge.net/
COMMENT=	C++ wrapper for GtkGLExt
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config perl gm4
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	gdkglextmm.pc.in
PKGCONFIG_OVERRIDE+=	gtkglextmm.pc.in


.include "../../devel/glibmm/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../devel/pangomm/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtkglext+=	gtkglext>=1.2.0
.include "../../graphics/gtkglext/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtkmm+=	gtkmm>=2.8
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
