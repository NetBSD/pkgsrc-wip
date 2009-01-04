# $NetBSD: Makefile,v 1.5 2009/01/04 18:16:45 thomasklausner Exp $
#

DISTNAME=	vinagre-2.24.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/vinagre/2.24/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://projects.gnome.org/vinagre/
COMMENT=	VNC client for GNOME

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	GCONF_SCHEMA_FILE_DIR=${PREFIX}/share/gconf/schemas/
MAKE_ENV+=	GCONF_SCHEMA_FILE_DIR=${PREFIX}/share/gconf/schemas/
USE_DIRS=	xdg-1.4 gnome2-1.6
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool pkg-config

GCONF_SCHEMAS+=	vinagre.schemas

.include "../../databases/shared-mime-info/mimedb.mk"
BUILDLINK_API_DEPENDS.GConf+=	GConf>=2.16.0
.include "../../devel/GConf/schemas.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.17.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libglade+=	libglade>=2.6.0
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/avahi/buildlink3.mk"
.include "../../wip/gtk-vnc/buildlink3.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/rarian/omf.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.13.1
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
