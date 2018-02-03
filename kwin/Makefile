# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kwin-${PLASMAVER}
CATEGORIES=	x11

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	KDE Window manager
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../wip/kde5/plasma.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools
DEPENDS+=	kinit>=5.21.0:../../x11/kinit

USE_TOOLS+=	msgmerge pkg-config

# generation of module.moc fails when ${PREFIX}/include in the moc include path
SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/kcmkwin/kwinscripts/CMakeFiles/kcm_kwin_scripts_autogen.dir/AutogenInfo.cmake
SUBST_FILES.fix-moc+=	_KDE_build/kcmkwin/kwincompositing/CMakeFiles/kwincompositing_autogen.dir/AutogenInfo.cmake
SUBST_FILES.fix-moc+=	_KDE_build/kcmkwin/kwinscreenedges/CMakeFiles/kcm_kwinscreenedges_autogen.dir/AutogenInfo.cmake
SUBST_FILES.fix-moc+=	_KDE_build/kcmkwin/kwinscreenedges/CMakeFiles/kcm_kwintouchscreen_autogen.dir/AutogenInfo.cmake
SUBST_FILES.fix-moc+=	_KDE_build/CMakeFiles/kwin_autogen.dir/AutogenInfo.cmake
SUBST_SED.fix-moc=	-e 's,;${PREFIX}/include;,;,g'

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	post-patch
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	data/CMakeLists.txt
SUBST_FILES.xdg+=	kcmkwin/kwincompositing/CMakeLists.txt
SUBST_FILES.xdg+=	kcmkwin/kwinscripts/CMakeLists.txt
SUBST_FILES.xdg+=	kcmkwin/kwintabbox/CMakeLists.txt
SUBST_FILES.xdg+=	plugins/kdecorations/aurorae/src/CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'
SUBST_SED.xdg+=		-e 's:{CONFIG_INSTALL_DIR}:{KDE_INSTALL_XDG_EX_DIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/aurorae.knsrc \
		${PKG_SYSCONFDIR}/xdg/aurorae.knsrc
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/kwineffect.knsrc \
		${PKG_SYSCONFDIR}/xdg/kwineffect.knsrc
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/kwinscripts.knsrc \
		${PKG_SYSCONFDIR}/xdg/kwinscripts.knsrc
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/kwinswitcher.knsrc \
		${PKG_SYSCONFDIR}/xdg/kwinswitcher.knsrc
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/org_kde_kwin.categories \
		${PKG_SYSCONFDIR}/xdg/org_kde_kwin.categories

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/kcmutils/buildlink3.mk"
.include "../../wip/kdecoration/buildlink3.mk"
.include "../../devel/kio/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../wip/kscreenlocker/buildlink3.mk"
.include "../../x11/plasma-framework/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/xcb-util-cursor/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
