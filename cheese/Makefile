# $NetBSD: Makefile,v 1.59 2015/10/10 01:58:09 ryoon Exp $

DISTNAME=	cheese-3.18.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/cheese/3.18/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/projects/cheese/
COMMENT=	Use your webcam to take photos and videos
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	gettext-m4-[0-9]*:../../devel/gettext-m4
DEPENDS+=	gst-plugins1-theora-[0-9]*:../../multimedia/gst-plugins1-theora
DEPENDS+=	gst-plugins1-ogg-[0-9]*:../../multimedia/gst-plugins1-ogg
DEPENDS+=	gst-plugins1-vorbis-[0-9]*:../../audio/gst-plugins1-vorbis

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-[5-9]*) || !empty(MACHINE_PLATFORM:MLinux)
DEPENDS+=	gst-plugins1-v4l2-[0-9]*:../../multimedia/gst-plugins1-v4l2
.endif

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config perl intltool gmake msgfmt
USE_TOOLS+=		autoconf automake autoreconf
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

GLIB_SCHEMAS+=		org.gnome.cheese.gschema.xml

#pre-configure:
#	cd ${WRKSRC} && autoreconf -fiv

.include "options.mk"

DEPENDS+=	yelp-3*:../../misc/yelp3

#.include "../../net/libgdata/buildlink3.mk"
BUILDLINK_API_DEPENDS.GConf+=	GConf>=2.16.0
.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.39.90
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.pango+=		pango>=1.18.0
.include "../../devel/pango/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=		cairo>=1.4.0
.include "../../graphics/cairo/buildlink3.mk"
BUILDLINK_API_DEPENDS.librsvg+=		librsvg>=2.18.0
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
#BUILDLINK_API_DEPENDS.evolution-data-server+=	evolution-data-server>=1.12.0
.include "../../wip/evolution-data-server/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/gst-plugins1-bad/buildlink3.mk"
.include "../../graphics/clutter/buildlink3.mk"
.include "../../wip/clutter-gst/buildlink3.mk"
.include "../../multimedia/gst-plugins1-good/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus+=		dbus>=1.0
.include "../../sysutils/dbus/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus-glib+=	dbus-glib>=0.70
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../x11/gnome-desktop3/buildlink3.mk"
.include "../../graphics/clutter-gtk/buildlink3.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk3+>=3.13.4
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
