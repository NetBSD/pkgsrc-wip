# $NetBSD: Makefile,v 1.1.1.1 2010/08/11 10:41:28 jihbed Exp $
#

DISTNAME=	gtkglextmm-1.2.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkglext/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://gtkglext.sourceforge.net/
COMMENT=	C++ wrapper for GtkGLExt
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

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
