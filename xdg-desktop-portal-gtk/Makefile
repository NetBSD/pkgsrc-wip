# $NetBSD$

DISTNAME=	xdg-desktop-portal-gtk-1.15.3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=flatpak/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/flatpak/xdg-desktop-portal-gtk/
COMMENT=	Gtk implementation of xdg-desktop-portal
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config


.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
#.include "../../devel/libportal/buildlink3.mk"
#.include "../../geography/geoclue/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
#.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
#.include "../../wip/pipewire/buildlink3.mk"
.include "../../wip/xdg-desktop-portal/buildlink3.mk"
#.include "../../textproc/json-glib/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
#.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
