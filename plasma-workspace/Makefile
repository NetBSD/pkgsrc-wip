# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	plasma-workspace-${PLASMAVER}
CATEGORIES=	x11

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	KDE Plasma Workspace
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1 AND gnu-fdl-v1.2

.include "../../wip/kde5/plasma.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../wip/kdoctools
DEPENDS+=	breeze>=${PLASMAVER}:../../wip/breeze
DEPENDS+=	kactivitymanagerd>=${PLASMAVER}:../../wip/kactivitymanagerd
DEPENDS+=	kde-cli-tools>=${PLASMAVER}:../../wip/kde-cli-tools
DEPENDS+=	kwin>=${PLASMAVER}:../../wip/kwin
DEPENDS+=	milou>=${PLASMAVER}:../../wip/milou
DEPENDS+=	plasma-integration>=${PLASMAVER}:../../wip/plasma-integration

USE_TOOLS+=	msgmerge pkg-config

# generation of ksmserver.moc fails when ${PREFIX}/include in the moc include path
SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/ksmserver/CMakeFiles/kdeinit_ksmserver_automoc.dir/AutogenInfo.cmake
SUBST_FILES.fix-moc+=	_KDE_build/runners/windows/CMakeFiles/krunner_windows_automoc.dir/AutogenInfo.cmake
SUBST_FILES.fix-moc+=	_KDE_build/applets/notifications/lib/CMakeFiles/plasma_applet_notifications_automoc.dir/AutogenInfo.cmake
SUBST_SED.fix-moc=	-e 's,;${PREFIX}/include;,;,g'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/autostart
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/autostart/krunner.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/krunner.desktop
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/autostart/plasmashell.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/plasmashell.desktop
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/autostart/org.kde.klipper.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/org.kde.klipper.desktop
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/autostart/xembedsniproxy.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/xembedsniproxy.desktop
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/plasmoids.knsrc \
		${PKG_SYSCONFDIR}/xdg/plasmoids.knsrc
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/wallpaper.knsrc \
		${PKG_SYSCONFDIR}/xdg/wallpaper.knsrc
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/taskmanagerrulesrc \
		${PKG_SYSCONFDIR}/xdg/taskmanagerrulesrc

.include "../../math/cln/buildlink3.mk"
.include "../../math/qalculate/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../wip/baloo5/buildlink3.mk"
.include "../../wip/kdelibs4support/buildlink3.mk"
.include "../../wip/kdesu/buildlink3.mk"
.include "../../wip/kjsembed/buildlink3.mk"
.include "../../wip/knewstuff/buildlink3.mk"
.include "../../wip/knotifyconfig/buildlink3.mk"
.include "../../wip/krunner/buildlink3.mk"
.include "../../wip/kscreenlocker/buildlink3.mk"
.include "../../wip/ktexteditor/buildlink3.mk"
.include "../../wip/kxmlgui/buildlink3.mk"
.include "../../wip/kxmlrpcclient/buildlink3.mk"
.include "../../wip/libkscreen/buildlink3.mk"
.include "../../wip/libksysguard/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
