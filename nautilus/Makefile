# $NetBSD: Makefile,v 1.138 2015/04/25 14:24:54 tnn Exp $

DISTNAME=		nautilus-3.16.2
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/nautilus/3.16/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://live.gnome.org/Nautilus
COMMENT=		Nautilus file manager for GNOME3
#LICENSE=		gnu-gpl-v2 AND gnu-fdl-v1.1 AND gnu-lgpl-v2 AND TRADEMARK_NOTICE

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	libnautilus-extension/libnautilus-extension.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

GCONF_SCHEMAS=		apps_nautilus_preferences.schemas

# Fails to find tracker-common which is in a subdirectory.
# /usr/bin/ld: cannot find -ltracker-common
LDFLAGS+=		-L${PREFIX}/lib/tracker-1.0

# needed for nautilus-2.28 and gtk2-2.20 -- remove on next update
BUILDLINK_TRANSFORM+=	rm:-DG_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=	rm:-DGDK_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=	rm:-DGDK_PIXBUF_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=	rm:-DGTK_DISABLE_DEPRECATED

# current default path
INSTALLATION_DIRS+=	lib/nautilus/extensions-2.0


# XXX this should maybe move to gnome-desktop3?
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"

.include "../../wip/meta-tracker/buildlink3.mk"
#.include "../../net/libgdata/buildlink3.mk"
#.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/exempi/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.17.5
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
#.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gnome-desktop3/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.13.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt?=	build
.include "../../x11/libXt/buildlink3.mk"
#.include "../../x11/libunique/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
