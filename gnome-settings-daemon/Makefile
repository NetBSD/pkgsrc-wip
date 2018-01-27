# $NetBSD: Makefile,v 1.54 2015/04/25 14:24:52 tnn Exp $

DISTNAME=	gnome-settings-daemon-3.16.4
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-settings-daemon/3.16/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	GNOME settings daemon

BUILD_DEPENDS+=	gdbus-codegen-[0-9]*:../../devel/gdbus-codegen
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gmake msgfmt

CONFLICTS+=	gnome-control-center<2.22.0

CONFIGURE_ARGS=		--disable-gudev
CONFIGURE_ARGS+=	--disable-rfkill
CONFIGURE_ARGS+=	--disable-network-manager

PYTHON_VERSIONS_ACCEPTED=	27

GCONF_SCHEMAS+=		gnome-settings-daemon.schemas
GCONF_SCHEMAS+=		desktop_gnome_font_rendering.schemas
GCONF_SCHEMAS+=		desktop_gnome_keybindings.schemas
GCONF_SCHEMAS+=		apps_gnome_settings_daemon_keybindings.schemas
GCONF_SCHEMAS+=		apps_gnome_settings_daemon_xrandr.schemas
GCONF_SCHEMAS+=		apps_gnome_settings_daemon_housekeeping.schemas
GCONF_SCHEMAS+=		desktop_gnome_peripherals_touchpad.schemas
GCONF_SCHEMAS+=		desktop_gnome_peripherals_smartcard.schemas
PKGCONFIG_OVERRIDE+=	data/gnome-settings-daemon.pc.in

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus-glib+=	dbus-glib>=0.74
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
#BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.21.2
.include "../../x11/gtk3/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgnomekbd+=	libgnomekbd>=2.31.2
.include "../../x11/libgnomekbd/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxklavier+=	libxklavier>=5.0
.include "../../x11/libxklavier/buildlink3.mk"
BUILDLINK_API_DEPENDS.gsettings-desktop-schemas+=	gsettings-desktop-schemas>=3.15.4
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../x11/gnome-desktop3/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../sysutils/upower/buildlink3.mk"
.include "../../wip/colord/buildlink3.mk"
.include "../../wip/geoclue/buildlink3.mk"
.include "../../wip/geocode-glib/buildlink3.mk"
.include "../../wip/libgweather/buildlink3.mk"
.include "../../security/polkit/buildlink3.mk"
.include "../../print/cups-base/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
