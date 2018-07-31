# $NetBSD: Makefile,v 1.2 2015/02/19 18:01:20 jihbed Exp $

DISTNAME=	cinnamon-settings-daemon-3.8.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=linuxmint/}
GITHUB_PROJECT=	cinnamon-settings-daemon
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/linuxmint/cinnamon-settings-daemon
COMMENT=	Settings daemon for Cinnamon
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config automake autoreconf intltool msgfmt
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--disable-smartcard-support

SUBST_CLASSES=		egdir
SUBST_MESSAGE.egdir=	Adapting Makefiles for CONF_FILES.
SUBST_FILES.egdir=	plugins/*/Makefile.am
SUBST_STAGE.egdir=	post-patch
SUBST_SED.egdir=	-e 's,.(sysconfdir)/xdg,$$(datadir)/examples/cinnamon-settings-daemon,'
SUBST_SED.egdir+=	-e 's,.(sysconfdir)/dbus-1,$$(datadir)/examples/dbus-1,'

EGDIR=			${PREFIX}/share/examples/cinnamon-settings-daemon/autostart
AUDIR=			${PKG_SYSCONFDIR}/xdg/autostart

CONF_FILES+=		${EGDIR}/cinnamon-settings-daemon-a11y-keyboard.desktop		\
			${AUDIR}/cinnamon-settings-daemon-a11y-keyboard.desktop		\
			${EGDIR}/cinnamon-settings-daemon-a11y-settings.desktop		\
			${AUDIR}/cinnamon-settings-daemon-a11y-settings.desktop		\
			${EGDIR}/cinnamon-settings-daemon-automount.desktop		\
			${AUDIR}/cinnamon-settings-daemon-automount.desktop		\
			${EGDIR}/cinnamon-settings-daemon-background.desktop		\
			${AUDIR}/cinnamon-settings-daemon-background.desktop		\
			${EGDIR}/cinnamon-settings-daemon-clipboard.desktop		\
			${AUDIR}/cinnamon-settings-daemon-clipboard.desktop		\
			${EGDIR}/cinnamon-settings-daemon-color.desktop			\
			${AUDIR}/cinnamon-settings-daemon-color.desktop			\
			${EGDIR}/cinnamon-settings-daemon-cursor.desktop		\
			${AUDIR}/cinnamon-settings-daemon-cursor.desktop		\
			${EGDIR}/cinnamon-settings-daemon-housekeeping.desktop		\
			${AUDIR}/cinnamon-settings-daemon-housekeeping.desktop		\
			${EGDIR}/cinnamon-settings-daemon-keyboard.desktop		\
			${AUDIR}/cinnamon-settings-daemon-keyboard.desktop		\
			${EGDIR}/cinnamon-settings-daemon-mouse.desktop			\
			${AUDIR}/cinnamon-settings-daemon-mouse.desktop			\
			${EGDIR}/cinnamon-settings-daemon-orientation.desktop		\
			${AUDIR}/cinnamon-settings-daemon-orientation.desktop		\
			${EGDIR}/cinnamon-settings-daemon-power.desktop			\
			${AUDIR}/cinnamon-settings-daemon-power.desktop			\
			${EGDIR}/cinnamon-settings-daemon-screensaver-proxy.desktop	\
			${AUDIR}/cinnamon-settings-daemon-screensaver-proxy.desktop	\
			${EGDIR}/cinnamon-settings-daemon-sound.desktop			\
			${AUDIR}/cinnamon-settings-daemon-sound.desktop			\
			${EGDIR}/cinnamon-settings-daemon-xrandr.desktop		\
			${AUDIR}/cinnamon-settings-daemon-xrandr.desktop		\
			${EGDIR}/cinnamon-settings-daemon-xsettings.desktop		\
			${AUDIR}/cinnamon-settings-daemon-xsettings.desktop		\
			share/examples/dbus-1/system.d/org.cinnamon.SettingsDaemon.DateTimeMechanism.conf \
			${PKG_SYSCONFDIR}/dbus-1/system.d/org.cinnamon.SettingsDaemon.DateTimeMechanism.conf

pre-configure:
		cd ${WRKSRC} && NOCONFIGURE=1 ./autogen.sh

BUILD_DEPENDS+=	autoconf-archive-[0-9]*:../../devel/autoconf-archive
BUILD_DEPENDS+=	gettext-m4>=0.14.6:../../devel/gettext-m4

.include "../../devel/glib2/schemas.mk"
.include "../../print/cups-base/buildlink3.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/polkit/buildlink3.mk"
.include  "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../sysutils/upower/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libgnomekbd/buildlink3.mk"
.include "../../sysutils/accountsservice/buildlink3.mk"
.include "../../graphics/colord/buildlink3.mk"

.include "../../wip/cinnamon-desktop/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
