# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	plasma-workspace-${PLASMAVER}
CATEGORIES=	x11

HOMEPAGE=	https://kde.org/plasma-desktop/
COMMENT=	KDE Plasma Workspace
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/plasma5.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools
DEPENDS+=	breeze>=${PLASMAVER}:../../wip/breeze
DEPENDS+=	kactivitymanagerd>=${PLASMAVER}:../../wip/kactivitymanagerd
#DEPENDS+=	kde-cli-tools>=${PLASMAVER}:../../wip/kde-cli-tools
#DEPENDS+=	kwin>=${PLASMAVER}:../../wip/kwin
DEPENDS+=	kwin>=5.12.5:../../wip/kwin
DEPENDS+=	milou>=${PLASMAVER}:../../sysutils/milou
DEPENDS+=	plasma-integration>=${PLASMAVER}:../../wip/plasma-integration

USE_TOOLS+=	gmake msgmerge pkg-config
GCC_REQD+=	10	# default member initializers for bit-fields in kcms/lookandfeel/lookandfeelmanager.h

#CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Debug

# generation of ksmserver.moc fails when ${PREFIX}/include in the moc include path
SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/*/CMakeFiles/*_autogen.dir/AutogenInfo.json
SUBST_FILES.fix-moc+=	_KDE_build/*/*/CMakeFiles/*_autogen.dir/AutogenInfo.json
SUBST_FILES.fix-moc+=	_KDE_build/*/*/*/CMakeFiles/*_autogen.dir/AutogenInfo.json
SUBST_NOOP_OK.fix-moc=	yes
SUBST_SED.fix-moc=	-e 's;"${PREFIX}/include",;;g'

#SUBST_CLASSES+=		qtpath
#SUBST_FILES.qtpath=	startkde/startkde.cmake
#SUBST_VARS.qtpath=	QTDIR
#SUBST_STAGE.qtpath=	post-patch

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg+=	gmenu-dbusmenu-proxy/CMakeLists.txt
SUBST_FILES.xdg+=	klipper/CMakeLists.txt
SUBST_FILES.xdg+=	libnotificationmanager/CMakeLists.txt
SUBST_FILES.xdg+=	libtaskmanager/CMakeLists.txt
SUBST_FILES.xdg+=	shell/CMakeLists.txt
SUBST_FILES.xdg+=	xembed-sni-proxy/CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'
SUBST_SED.xdg+=		-e 's:{KDE_INSTALL_AUTOSTARTDIR}:{KDE_INSTALL_AUTOSTARTEXDIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/autostart
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/autostart/gmenudbusmenuproxy.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/gmenudbusmenuproxy.desktop
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/autostart/klipper.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/klipper.desktop
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/autostart/org.kde.plasmashell.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/org.kde.plasmashell.desktop
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/autostart/xembedsniproxy.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/xembedsniproxy.desktop
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/plasmanotifyrc \
		${PKG_SYSCONFDIR}/xdg/plasmanotifyrc
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/taskmanagerrulesrc \
		${PKG_SYSCONFDIR}/xdg/taskmanagerrulesrc

.include "../../devel/kcmutils/buildlink3.mk"
.include "../../devel/kitemmodels/buildlink3.mk"
.include "../../devel/knotifyconfig/buildlink3.mk"
.include "../../devel/kpeople/buildlink3.mk"
.include "../../devel/krunner/buildlink3.mk"
.include "../../devel/ktexteditor/buildlink3.mk"
.include "../../graphics/libkexiv2/buildlink3.mk"
.include "../../graphics/prison/buildlink3.mk"
.include "../../math/cln/buildlink3.mk"
.include "../../math/qalculate/buildlink3.mk"
.include "../../misc/kquickcharts/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../net/kxmlrpcclient/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/baloo5/buildlink3.mk"
.include "../../security/kdesu/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../time/kholidays/buildlink3.mk"
.include "../../www/kjsembed/buildlink3.mk"
.include "../../x11/kactivities-stats/buildlink3.mk"
.include "../../wip/kscreenlocker/buildlink3.mk"
.include "../../x11/libkscreen/buildlink3.mk"
.include "../../sysutils/libksysguard/buildlink3.mk"
.include "../../x11/kdelibs4support/buildlink3.mk"	# for Solid/PowerManagement
.include "../../x11/kxmlgui/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
#.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
