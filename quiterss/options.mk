# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.quiterss

PKG_OPTIONS_REQUIRED_GROUPS=	qt
PKG_OPTIONS_GROUP.qt=		qt4 qt5

PKG_SUGGESTED_OPTIONS=		qt5

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mqt4)
.include "../../multimedia/phonon/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mqt5)
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.endif
