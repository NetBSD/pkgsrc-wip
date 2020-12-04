# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	plasma-desktop-${PLASMAVER}
PKGREVISION=	1
CATEGORIES=	x11

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	KDE Plasma Desktop
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/plasma5.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools
DEPENDS+=	ksysguard>=${PLASMAVER}:../../wip/ksysguard
DEPENDS+=	kmenuedit>=${PLASMAVER}:../../wip/kmenuedit
DEPENDS+=	polkit-kde-agent>=${PLASMAVER}:../../wip/polkit-kde-agent
DEPENDS+=	qt5-qtgraphicaleffects-[0-9]*:../../x11/qt5-qtgraphicaleffects

USE_TOOLS+=	msgmerge pkg-config

CMAKE_ARGS+=	-DKAUTH_DBUS_DIR=${PREFIX}/share/examples/plasma-desktop

SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	KDE_build/*/CMakeFiles/*_autogen.dir/AutogenInfo.cmake
SUBST_FILES.fix-moc+=	_KDE_build/*/*/CMakeFiles/*_autogen.dir/AutogenInfo.cmake
SUBST_FILES.fix-moc+=	_KDE_build/*/*/*/CMakeFiles/*_autogen.dir/AutogenInfo.cmake
SUBST_SED.fix-moc=	-e 's,;${PREFIX}/include;,;,g'

SUBST_CLASSES+=		qlc
SUBST_STAGE.qlc=	pre-configure
SUBST_MESSAGE.qlc=	Move to new KDE location
SUBST_FILES.qlc=	CMakeLists.txt
SUBST_SED.qlc=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_LOGGINGCATEGORIESDIR}:'

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
.include "../../devel/kitemmodels/buildlink3.mk"
.include "../../devel/knotifyconfig/buildlink3.mk"
.include "../../devel/kpeople/buildlink3.mk"
.include "../../devel/krunner/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/baloo5/buildlink3.mk"
.include "../../wip/systemsettings/buildlink3.mk"
.include "../../x11/kactivities-stats/buildlink3.mk"
.include "../../x11/kdelibs4support/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/plasma-framework/buildlink3.mk"
.include "../../wip/plasma-workspace/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/xkeyboard-config/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
