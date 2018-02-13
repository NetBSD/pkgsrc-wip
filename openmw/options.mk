# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.openmw
PKG_OPTIONS_GROUP.qt=		qt4 qt5
PKG_OPTIONS_OPTIONAL_GROUPS=	qt
PKG_SUGGESTED_OPTIONS=		qt5

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	gui

.if !empty(PKG_OPTIONS:Mqt5)
PLIST.gui=	yes
CMAKE_ARGS+=	-DDESIRED_QT_VERSION=5
.include "../../x11/qt5-qtbase/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mqt4)
PLIST.gui=	yes
CMAKE_ARGS+=	-DDESIRED_QT_VERSION=4
.include "../../x11/qt4-libs/buildlink3.mk"
.else
CMAKE_ARGS+=	-DBUILD_LAUNCHER=0
CMAKE_ARGS+=	-DBUILD_OPENCS=0
CMAKE_ARGS+=	-DBUILD_WIZARD=0
.endif
