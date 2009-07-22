# $NetBSD: Makefile,v 1.2 2009/07/22 09:53:17 thomasklausner Exp $
#

DISTNAME=	tasks-0.15
CATEGORIES=	time editors
MASTER_SITES=	http://pimlico-project.org/sources/tasks/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pimlico-project.org/tasks.html
COMMENT=	Tasks is a simple To Do list application for GNOME

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	intltool pkg-config gmake

CONFIGURE_ARGS+=	--disable-omoko
CONFIGURE_ARGS+=	--disable-hildon
CONFIGURE_ARGS+=	--without-owl

BUILDLINK_API_DEPENDS.glib2+=      glib2>=2.12.0
BUILDLINK_ABI_DEPENDS.gtk2+=	gtk2+>=2.8.17nb1

.include "../../devel/glib2/buildlink3.mk"
#.include "../../devel/libsexy/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
CONFIGURE_ARGS+=	--enable-gtk
.include "../../x11/gtk2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-unique
.include "../../x11/libunique/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
