# $NetBSD: options.mk,v 1.2 2014/12/04 15:51:25 nros Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.qupzilla
PKG_OPTIONS_REQUIRED_GROUPS= qt
PKG_OPTIONS_GROUP.qt=	qt4 qt5
PKG_SUGGESTED_OPTIONS=	qt4
.include "../../mk/bsd.options.mk"


.if !empty(PKG_OPTIONS:Mqt5)
.include "../../x11/qt5-dbus/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mqt4)
.include "../../x11/qt4-qdbus/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
DEPENDS+=qt4-sqlite3>=4.7:../../x11/qt4-sqlite3
.endif
