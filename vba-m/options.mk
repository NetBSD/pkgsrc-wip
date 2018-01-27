# $NetBSD: options.mk,v 1.3 2014/08/11 23:10:14 thomasklausner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.vba-m
PKG_SUPPORTED_OPTIONS=	debug ffmpeg gtk lirc nls sdl
PKG_SUGGESTED_OPTIONS=	debug ffmpeg gtk nls sdl
PLIST_VARS+=		gtk nls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CMAKE_ARGS+=	-DENABLE_DEBUGGER=ON
.else
CMAKE_ARGS+=	-DENABLE_DEBUGGER=OFF
.endif

.if !empty(PKG_OPTIONS:Mffmpeg)
.include "../../multimedia/ffmpeg1/buildlink3.mk"
CMAKE_ARGS+=	-DENABLE_FFMPEG=ON
.else
CMAKE_ARGS+=	-DENABLE_FFMPEG=OFF
.endif

.if !empty(PKG_OPTIONS:Mgtk)
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/gtkglextmm/buildlink3.mk"
CMAKE_ARGS+=	-DENABLE_GTK=ON
PLIST.gtk=	yes
.else
CMAKE_ARGS+=	-DENABLE_GTK=OFF
.endif

.if !empty(PKG_OPTIONS:Mlirc)
.include "../../comms/lirc/buildlink3.mk"
CMAKE_ARGS+=	-DENABLE_LIRC=ON
.else
CMAKE_ARGS+=	-DENABLE_LIRC=OFF
.endif

.if !empty(PKG_OPTIONS:Mnls)
.include "../../devel/gettext-lib/buildlink3.mk"
CMAKE_ARGS+=	-DENABLE_NLS=ON
PLIST.nls=	yes
.else
CMAKE_ARGS+=	-DENABLE_NLS=OFF
.endif

.if !empty(PKG_OPTIONS:Msdl)
.include "../../devel/SDL/buildlink3.mk"
CMAKE_ARGS+=	-DENABLE_SDL=ON
.else
CMAKE_ARGS+=	-DENABLE_SDL=OFF
.endif
