# $NetBSD: Makefile,v 1.134 2015/12/05 21:26:07 adam Exp $

DISTNAME=		gnome-applets-3.18.2
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-applets/3.18/}
EXTRACT_SUFX=		.tar.xz
LICENSE=		gnu-gpl-v2 AND gnu-fdl-v1.1

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnome.org/
COMMENT=		GNOME2 panel applets

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-ORBit via py-gnome2

.include "options.mk"

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
# obsolete; replaced by PA mixer in gnome-media>=2.26
CONFIGURE_ARGS+=	--enable-mixer-applet
# obsolete; replaced by gnome-power-manager>=2.24
CONFIGURE_ARGS+=	--disable-cpufreq

EGDIR=			${PREFIX}/share/examples/gnome-applets

GCONF_SCHEMAS=		charpick.schemas
GCONF_SCHEMAS+=		drivemount.schemas
GCONF_SCHEMAS+=		geyes.schemas
#GCONF_SCHEMAS+=	gswitchit.schemas
GCONF_SCHEMAS+=		mixer.schemas
GCONF_SCHEMAS+=		multiload.schemas
GCONF_SCHEMAS+=		stickynotes.schemas

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		battstat
.if ${OPSYS} == "Linux" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD" || \
    (${OPSYS} == "NetBSD" && exists(/usr/include/machine/apmvar.h))
GCONF_SCHEMAS+=		battstat.schemas
PLIST.battstat=		yes
CONF_FILES+=		${EGDIR}/sound/events/battstat_applet.soundlist \
			${PKG_SYSCONFDIR}/sound/events/battstat_applet.soundlist
.else
CONFIGURE_ARGS+=	--disable-battstat
.endif

PRINT_PLIST_AWK+=	/[Bb]attstat/ { print "$${PLIST.battstat}"$$0; next; }
PRINT_PLIST_AWK+=	/examples/ { print "$${PLIST.battstat}"$$0; next; }

.include "../../devel/GConf/schemas.mk"

PY_PATCHPLIST=		yes
REPLACE_PYTHON+=	invest-applet/invest/invest-applet.py
REPLACE_PYTHON+=	invest-applet/invest/invest-chart

.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=			glib2>=2.18.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgweather+=	libgweather>=2.22.1
.include "../../wip/libgweather/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../fonts/gucharmap/buildlink3.mk"
BUILDLINK_API_DEPENDS.gnome-icon-theme+=	gnome-icon-theme>=2.15.91
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../wip/colord/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/omf-scrollkeeper.mk"
BUILDLINK_API_DEPENDS.gst-plugins1-base+=	gst-plugins1-base>=0.10.2
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
BUILDLINK_API_DEPENDS.gstreamer1+=		gstreamer1>=0.10.2
.include "../../multimedia/gstreamer1/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus+=	dbus>=1.1.2
.include "../../sysutils/dbus/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus-glib+=	dbus-glib>=0.74
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../wip/gnome-settings-daemon/buildlink3.mk"
#.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../wip/gnome-control-center/buildlink3.mk"
.include "../../x11/gnome-desktop3/buildlink3.mk"
BUILDLINK_API_DEPENDS.gnome-panel+=	gnome-panel>=2.31.2
.include "../../wip/gnome-panel/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=			gtk2+>=2.13.0
.include "../../x11/gtk2/buildlink3.mk"
#.include "../../x11/libgnomekbd/buildlink3.mk"
#.include "../../x11/libxklavier/buildlink3.mk"
#.include "../../x11/py-gnome2-desktop/buildlink3.mk"
#.include "../../x11/py-gnome2/buildlink3.mk"

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
