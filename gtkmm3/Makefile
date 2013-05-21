# $NetBSD: Makefile,v 1.3 2013/05/21 13:51:48 thomasklausner Exp $

DISTNAME=	gtkmm-3.8.0
PKGNAME=	${DISTNAME:S/gtkmm/gtkmm3/1}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtkmm/3.8/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gtkmm.org/
COMMENT=	C++ Interfaces for GTK+ and GNOME
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

USE_TOOLS+=	gmake perl pkg-config
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	gtk/gtkmm.pc.in
PKGCONFIG_OVERRIDE+=	gdk/gdkmm.pc.in

#BUILD_DEPENDS+=		libsigc++-[0-9]*:../../devel/libsigc++
#BUILD_DEPENDS+=		gdk-pixbuf2>=2.22.1:../../graphics/gdk-pixbuf2
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/atkmm/buildlink3.mk"
.include "../../graphics/cairomm/buildlink3.mk"
BUILDLINK_ABI_DEPENDS.gtk3+=	gtk3+>=3.8.0
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/pangomm/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
