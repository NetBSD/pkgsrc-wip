# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.sddm
PKG_OPTIONS_REQUIRED_GROUPS+=	gui
PKG_OPTIONS_GROUP.gui=		qt5 qt6
PKG_SUGGESTED_OPTIONS+=		qt6

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if ${PKG_OPTIONS:Mqt5}
PLIST_SRC=PLIST.qt5
CMAKE_CONFIGURE_ARGS+=	-DBUILD_WITH_QT6=OFF
BUILDLINK_API_DEPENDS.qt5-qtbase+=     qt5-qtbase>=5.15.17
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.endif

.if ${PKG_OPTIONS:Mqt6}
CMAKE_CONFIGURE_ARGS+=	-DBUILD_WITH_QT6=ON
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.endif
