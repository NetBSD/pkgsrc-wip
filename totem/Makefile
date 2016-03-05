# $NetBSD: Makefile,v 1.81 2015/10/10 01:58:14 ryoon Exp $

.include "Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org

USE_TOOLS+=	automake autoreconf

DEPENDS+=	gst-plugins1-soup-[0-9]*:../../net/gst-plugins1-soup

COMMENT=	(using GStreamer)

CONFLICTS+=	totem-xine-[0-9]*

CONFIGURE_ARGS+=	--disable-browser-plugins

#BUILDLINK_API_DEPENDS.gst-plugins1-base+=	gst-plugins1-base>=1.7

#DEPENDS+=	grilo-plugins>=0.3.0:../../wip/grilo-plugins

#.include "../../devel/GConf/buildlink3.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libpeas/buildlink3.mk"
.include "../../devel/py-gobject3/buildlink3.mk"
.include "../../x11/gnome-desktop3/buildlink3.mk"
.include "../../wip/grilo/buildlink3.mk"
.include "../../graphics/clutter/buildlink3.mk"
.include "../../wip/clutter-gst/buildlink3.mk"
.include "../../graphics/clutter-gtk/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/gst-plugins1-good/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../net/libgdata/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
