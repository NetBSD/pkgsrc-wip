# $NetBSD: options.mk,v 1.3 2013/11/13 02:28:18 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fceux
PKG_SUPPORTED_OPTIONS=	debug gd gtk2 gtk3 opengl sdl x11 zlib
PKG_SUGGESTED_OPTIONS=	gtk2 opengl sdl x11 zlib

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
MAKE_ENV+=		DEBUG=1
.else
MAKE_ENV+=		DEBUG=0
.endif

.if !empty(PKG_OPTIONS:Mgd)
#PLIST.gd=           yes
.include "../../graphics/gd/buildlink3.mk"
.else
.endif

.if !empty(PKG_OPTIONS:Mgtk2)
#PLIST.gtk2=           yes
BUILDLINK_API_DEPENDS.gtk2+=   gtk2+>=2.18
.include "../../x11/gtk2/buildlink3.mk"
MAKE_ENV+=		GTK=1 GTK3=0
.else
MAKE_ENV+=		GTK=0
.endif

.if !empty(PKG_OPTIONS:Mgtk3)
#PLIST.gtk3=		yes
.include "../../x11/gtk3/buildlink3.mk"
MAKE_ENV+=		GTK3=1 GTK=0
.else
MAKE_ENV+=		GTK3=0
.endif

#.if !empty(PKG_OPTIONS:Mlua)
##PLIST.lua=		yes
#LUA_VERSION_REQD=	51
#.include "../../lang/lua/buildlink3.mk"
#MAKE_ENV+=		LUA=1
#.else
#MAKE_ENV+=		LUA=0
#.endif

.if !empty(PKG_OPTIONS:Mopengl)
#PLIST.opengl=           yes
.include "../../graphics/MesaLib/buildlink3.mk"
MAKE_ENV+=		OPENGL=1
.else
MAKE_ENV+=		OPENGL=0
.endif

.if !empty(PKG_OPTIONS:Msdl)
.include "../../devel/SDL/buildlink3.mk"
MAKE_ENV+=		CREATE_AVI=1 LOGO=1
.else
MAKE_ENV+=		CREATE_AVI=0 LOGO=0
.endif

.if !empty(PKG_OPTIONS:Mx11)
#PLIST.x11=              yes
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt?=     build # only for configure
.include "../../x11/libXt/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mzlib)
BUILDLINK_API_DEPENDS.zlib+=   zlib>=1.2
.include "../../devel/zlib/buildlink3.mk"
.endif
