# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	plasma-workspace-${PLASMAVER}
CATEGORIES=	x11

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	KDE Plasma Workspace
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1 AND gnu-fdl-v1.2

.include "../../wip/kde5/plasma.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools
DEPENDS+=	breeze>=${PLASMAVER}:../../wip/breeze
DEPENDS+=	kactivitymanagerd>=${PLASMAVER}:../../wip/kactivitymanagerd
DEPENDS+=	kde-cli-tools>=${PLASMAVER}:../../wip/kde-cli-tools
DEPENDS+=	kwin>=${PLASMAVER}:../../wip/kwin
DEPENDS+=	milou>=${PLASMAVER}:../../wip/milou
DEPENDS+=	plasma-integration>=${PLASMAVER}:../../wip/plasma-integration

USE_TOOLS+=	msgmerge pkg-config

#CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Debug

# generation of ksmserver.moc fails when ${PREFIX}/include in the moc include path
SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/ksmserver/CMakeFiles/kdeinit_ksmserver_autogen.dir/AutogenInfo.cmake
SUBST_FILES.fix-moc+=	_KDE_build/runners/windows/CMakeFiles/krunner_windows_autogen.dir/AutogenInfo.cmake
SUBST_FILES.fix-moc+=	_KDE_build/applets/notifications/lib/CMakeFiles/plasma_applet_notifications_autogen.dir/AutogenInfo.cmake
SUBST_SED.fix-moc=	-e 's,;${PREFIX}/include;,;,g'

SUBST_CLASSES+=		qtpath
SUBST_FILES.qtpath=	startkde/startkde.cmake
SUBST_VARS.qtpath=	QTDIR
SUBST_STAGE.qtpath=	post-patch

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	post-patch
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	components/shellprivate/CMakeLists.txt
SUBST_FILES.xdg+=	klipper/CMakeLists.txt
SUBST_FILES.xdg+=	krunner/CMakeLists.txt
SUBST_FILES.xdg+=	kuiserver/CMakeLists.txt
SUBST_FILES.xdg+=	libtaskmanager/CMakeLists.txt
SUBST_FILES.xdg+=	shell/CMakeLists.txt
SUBST_FILES.xdg+=	wallpapers/image/CMakeLists.txt
SUBST_FILES.xdg+=	xembed-sni-proxy/CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'
SUBST_SED.xdg+=		-e 's:{KDE_INSTALL_AUTOSTARTDIR}:{KDE_INSTALL_AUTOSTARTEXDIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/autostart
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/autostart/krunner.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/krunner.desktop
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/autostart/org.kde.plasmashell.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/org.kde.plasmashell.desktop
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/autostart/klipper.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/klipper.desktop
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/autostart/xembedsniproxy.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/xembedsniproxy.desktop
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/kuiserver.categories \
		${PKG_SYSCONFDIR}/xdg/kuiserver.categories
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/plasmoids.knsrc \
		${PKG_SYSCONFDIR}/xdg/plasmoids.knsrc
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/wallpaper.knsrc \
		${PKG_SYSCONFDIR}/xdg/wallpaper.knsrc
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/taskmanagerrulesrc \
		${PKG_SYSCONFDIR}/xdg/taskmanagerrulesrc

.include "../../math/cln/buildlink3.mk"
.include "../../math/qalculate/buildlink3.mk"
.include "../../graphics/prison/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../sysutils/baloo5/buildlink3.mk"
.include "../../x11/kdelibs4support/buildlink3.mk"
.include "../../security/kdesu/buildlink3.mk"
.include "../../www/kjsembed/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../devel/knotifyconfig/buildlink3.mk"
.include "../../devel/krunner/buildlink3.mk"
.include "../../wip/kscreenlocker/buildlink3.mk"
.include "../../devel/ktexteditor/buildlink3.mk"
.include "../../x11/kxmlgui/buildlink3.mk"
.include "../../net/kxmlrpcclient/buildlink3.mk"
.include "../../wip/libkscreen/buildlink3.mk"
.include "../../wip/libksysguard/buildlink3.mk"
.include "../../wip/kholidays/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
