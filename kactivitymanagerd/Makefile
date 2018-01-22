# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kactivitymanagerd-${PLASMAVER}
CATEGORIES=	x11

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	System service to manage user's activities and track the usage patterns
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v3

.include "../../wip/kde5/plasma.mk"

USE_TOOLS+=	msgmerge pkg-config

# generation of virtualdesktopswitch.moc fails when ${PREFIX}/include in the moc include path
SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/src/service/plugins/virtualdesktopswitch/CMakeFiles/kactivitymanagerd_plugin_virtualdesktopswitch_autogen.dir/AutogenInfo.cmake
SUBST_FILES.fix-moc+=	_KDE_build/src/service/plugins/slc/CMakeFiles/kactivitymanagerd_plugin_slc_autogen.dir/AutogenInfo.cmake
SUBST_FILES.fix-moc+=	_KDE_build/src/service/plugins/sqlite/CMakeFiles/kactivitymanagerd_plugin_sqlite_autogen.dir/AutogenInfo.cmake
SUBST_FILES.fix-moc+=	_KDE_build/src/service/plugins/activitytemplates/CMakeFiles/kactivitymanagerd_plugin_activitytemplates_autogen.dir/AutogenInfo.cmake
SUBST_FILES.fix-moc+=	_KDE_build/src/service/plugins/globalshortcuts/CMakeFiles/kactivitymanagerd_plugin_globalshortcuts_autogen.dir/AutogenInfo.cmake
SUBST_FILES.fix-moc+=	_KDE_build/src/service/plugins/eventspy/CMakeFiles/kactivitymanagerd_plugin_eventspy_autogen.dir/AutogenInfo.cmake
SUBST_FILES.fix-moc+=	_KDE_build/src/service/plugins/runapplication/CMakeFiles/kactivitymanagerd_plugin_runapplication_autogen.dir/AutogenInfo.cmake
SUBST_SED.fix-moc=	-e 's,;${PREFIX}/include;,;,g'

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
