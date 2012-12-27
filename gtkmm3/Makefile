# $NetBSD: Makefile,v 1.2 2012/12/27 05:25:31 othyro Exp $
#

DISTNAME=	gtkmm-3.4.2
PKGNAME=	${DISTNAME:S/gtkmm/gtkmm3/1}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtkmm/3.4/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gtkmm.org/
COMMENT=	C++ Interfaces for GTK+ and GNOME
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_TOOLS+=	gmake perl pkg-config
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	gtkmm-3.0.1/gtk/PaxHeaders.31493/gtkmm.pc.in
PKGCONFIG_OVERRIDE+=	gtkmm-3.0.1/gtk/gtkmm.pc.in
PKGCONFIG_OVERRIDE+=	gtkmm-3.0.1/gdk/PaxHeaders.31493/gdkmm.pc.in
PKGCONFIG_OVERRIDE+=	gtkmm-3.0.1/gdk/gdkmm.pc.in

BUILD_DEPENDS+=		glib2-[0-9]*:../../devel/glib2
BUILD_DEPENDS+=		libsigc++-[0-9]*:../../devel/libsigc++
BUILD_DEPENDS+=		gdk-pixbuf2>=2.22.1:../../graphics/gdk-pixbuf2
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/atkmm/buildlink3.mk"
.include "../../graphics/cairomm/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/pangomm/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
