# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	plasma-desktop-${PLASMAVER}
CATEGORIES=	x11

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	KDE Plasma Desktop
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1 AND gnu-fdl-v1.2

.include "../../wip/kde5/plasma.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools
DEPENDS+=	ksysguard>=${PLASMAVER}:../../wip/ksysguard
DEPENDS+=	kmenuedit>=${PLASMAVER}:../../wip/kmenuedit
DEPENDS+=	polkit-kde-agent>=${PLASMAVER}:../../wip/polkit-kde-agent
DEPENDS+=	qt5-qtgraphicaleffects-[0-9]*:../../x11/qt5-qtgraphicaleffects

USE_TOOLS+=	msgmerge pkg-config

CMAKE_ARGS+=	-DKAUTH_DBUS_DIR=${PREFIX}/share/examples/plasma-desktop

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	post-patch
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	kcms/colors/CMakeLists.txt
SUBST_FILES.xdg+=	kcms/cursortheme/CMakeLists.txt
SUBST_FILES.xdg+=	kcms/desktoptheme/CMakeLists.txt
SUBST_FILES.xdg+=	kcms/emoticons/CMakeLists.txt
SUBST_FILES.xdg+=	kcms/icons/CMakeLists.txt
SUBST_FILES.xdg+=	kcms/kfontinst/kcmfontinst/CMakeLists.txt
SUBST_FILES.xdg+=	kcms/lookandfeel/CMakeLists.txt
SUBST_SED.xdg=		-e 's:{CONFIG_INSTALL_DIR}:{KDE_INSTALL_XDG_EX_DIR}:'
SUBST_SED.xdg+=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/colorschemes.knsrc \
		${PKG_SYSCONFDIR}/xdg/colorschemes.knsrc
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/emoticons.knsrc \
		${PKG_SYSCONFDIR}/xdg/emoticons.knsrc
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/icons.knsrc \
		${PKG_SYSCONFDIR}/xdg/icons.knsrc
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/kfontinst.knsrc \
		${PKG_SYSCONFDIR}/xdg/kfontinst.knsrc
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/lookandfeel.knsrc \
		${PKG_SYSCONFDIR}/xdg/lookandfeel.knsrc
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/plasma-themes.knsrc \
		${PKG_SYSCONFDIR}/xdg/plasma-themes.knsrc
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/xcursor.knsrc \
		${PKG_SYSCONFDIR}/xdg/xcursor.knsrc
CONF_FILES+=	${PREFIX}/share/examples/plasma-desktop/org.kde.fontinst.conf \
		${PKG_SYSCONFDIR}/dbus-1/system.d/org.kde.fontinst.conf
CONF_FILES+=	${PREFIX}/share/examples/plasma-desktop/org.kde.kcontrol.kcmclock.conf \
		${PKG_SYSCONFDIR}/dbus-1/system.d/org.kde.kcontrol.kcmclock.conf

MAKE_DIRS+=		${PKG_SYSCONFDIR}/dbus-1/system.d
INSTALLATION_DIRS+=	share/examples/plasma-desktop

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
pre-configure:
	ln -s /usr/lib/pkgconfig/xorg-evdev.pc ${BUILDLINK_DIR}/lib/pkgconfig/
	ln -s /usr/lib/pkgconfig/xorg-synaptics.pc ${BUILDLINK_DIR}/lib/pkgconfig/
.endif

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/baloo5/buildlink3.mk"
.include "../../x11/kactivities-stats/buildlink3.mk"
.include "../../x11/kdelibs4support/buildlink3.mk"
.include "../../devel/knotifyconfig/buildlink3.mk"
.include "../../devel/kpeople/buildlink3.mk"
.include "../../devel/krunner/buildlink3.mk"
.include "../../x11/plasma-framework/buildlink3.mk"
.include "../../wip/plasma-workspace/buildlink3.mk"
.include "../../wip/systemsettings/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/xkeyboard-config/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
