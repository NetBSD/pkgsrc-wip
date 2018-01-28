# $NetBSD: options.mk,v 1.4 2014/12/19 16:07:27 nros Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.qupzilla
PKG_OPTIONS_REQUIRED_GROUPS= qt
PKG_OPTIONS_GROUP.qt=	qt4 qt5
PKG_SUPPORTED_OPTIONS=	dbus
PKG_SUGGESTED_OPTIONS=	qt4 dbus
.include "../../mk/bsd.options.mk"


.if !empty(PKG_OPTIONS:Mqt5)
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mqt4)
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
DEPENDS+=qt4-sqlite3>=4.7:../../x11/qt4-sqlite3
.  if !empty(PKG_OPTIONS:Mdbus)
.include "../../x11/qt4-qdbus/buildlink3.mk"
.  else
MAKE_ENV+= DISABLE_DBUS=${TRUE}
.  endif
.endif
