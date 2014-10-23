# $NetBSD: options.mk,v 1.1 2014/10/23 20:08:20 nros Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.qupzilla
PKG_SUPPORTED_OPTIONS=	build-using-qt5
PLIST_VARS+=		qt5
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mbuild-using-qt5)
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
PLIST.qt5=yes
.else
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
DEPENDS+=qt4-sqlite3>=4.7:../../x11/qt4-sqlite3
.endif
