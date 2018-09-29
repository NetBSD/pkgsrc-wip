# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.gambas3-runtime
PKG_SUPPORTED_OPTIONS=	qt4 qt5 gtk2 gtk3
PKG_SUGGESTED_OPTIONS=	qt4
PLIST_VARS+=		gui gui.opengl gui.qt

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk2)
BUILD_DEPENDS+=		gambas3-gb-gtk-opengl-${GB_VERSION}:../../wip/gambas3-gb-gtk-opengl
PLIST.gui=		yes
PLIST.gui.opengl=	yes
.endif

.if !empty(PKG_OPTIONS:Mgtk3)
BUILD_DEPENDS+=		gambas3-gb-gtk3-${GB_VERSION}:../../wip/gambas3-gb-gtk3
PLIST.gui=		yes
.endif

.if !empty(PKG_OPTIONS:Mqt4)
BUILD_DEPENDS+=		gambas3-gb-qt4-opengl-${GB_VERSION}:../../wip/gambas3-gb-qt4-opengl
BUILD_DEPENDS+=		gambas3-gb-qt4-webkit-${GB_VERSION}:../../wip/gambas3-gb-qt4-webkit
PLIST.gui=		yes
PLIST.gui.opengl=	yes
PLIST.gui.qt=		yes
.endif

.if !empty(PKG_OPTIONS:Mqt5)
BUILD_DEPENDS+=		gambas3-gb-qt5-opengl-${GB_VERSION}:../../wip/gambas3-gb-qt5-opengl
BUILD_DEPENDS+=		gambas3-gb-qt5-webkit-${GB_VERSION}:../../wip/gambas3-gb-qt5-webkit
PLIST.gui=		yes
PLIST.gui.opengl=	yes
PLIST.gui.qt=		yes
.endif
