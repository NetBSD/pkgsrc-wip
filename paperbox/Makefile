# $NetBSD: Makefile,v 1.1.1.1 2010/05/01 22:44:52 thomasklausner Exp $
#

DISTNAME=	paperbox-0.4.4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/paperbox/0.4/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/PaperBox
COMMENT=	Document browser
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake intltool pkg-config

CPPFLAGS+=	-D__ASSERT_FUNCTION=__func__

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../textproc/rarian/buildlink3.mk"
BUILDLINK_API_DEPENDS.glibmm+=	glibmm>=2.16.0
.include "../../devel/glibmm/buildlink3.mk"
.include "../../devel/libglademm/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgnomeui+=	libgnomeui>=2.16.0
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtkmm+=	gtkmm>=2.12.0
.include "../../x11/gtkmm/buildlink3.mk"
BUILDLINK_API_DEPENDS.goocanvas+=	goocanvas>=0.9
.include "../../graphics/goocanvas/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../wip/meta-tracker/buildlink3.mk"
.include "../../x11/gtkmm-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
