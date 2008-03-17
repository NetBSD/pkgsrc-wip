# $NetBSD: Makefile,v 1.3 2008/03/17 21:20:05 koifren Exp $
#

DISTNAME=	f-spot-0.4.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/f-spot/0.4/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://f-spot.org/
COMMENT=	Full-featured personal photo management application

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool pkg-config bash:run

MAKE_JOBS_SAFE=	no

PKGCONFIG_OVERRIDE+=	f-spot.pc.in

REPLACE_BASH+=	icon-theme-installer
REPLACE_BASH+=	src/f-spot.in
REPLACE_BASH+=	tools/f-spot-import

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk2-sharp/buildlink3.mk"
.include "../../wip/ndesk-dbus-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
