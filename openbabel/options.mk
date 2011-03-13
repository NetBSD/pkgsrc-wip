# $NetBSD: options.mk,v 1.2 2011/03/13 03:45:52 ryo-on Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.openbabel
PKG_SUPPORTED_OPTIONS=	wx-gui
PKG_SUGGESTED_OPTIONS=

PLIST_VARS+=		wx-gui

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mwx-gui)
.  include "../../x11/wxGTK28/buildlink3.mk"
CMAKE_ARGS+=	-DBUILD_GUI=ON
PLIST.wx-gui=	yes
.else
CMAKE_ARGS+=	-DBUILD_GUI=OFF
.endif
