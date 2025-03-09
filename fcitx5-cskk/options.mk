# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.fcitx5-cskk

PKG_SUPPORTED_OPTIONS=	qt5
PKG_SUGGESTED_OPTIONS+=	qt5
PLIST_VARS+=		qt5

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mqt5)

PLIST.qt5=		yes
.include "../../inputmethod/fcitx5-qt/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"

.else

CMAKE_CONFIGURE_ARGS+=	-DENABLE_QT=Off

.endif
