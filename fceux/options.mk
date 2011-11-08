# $NetBSD: options.mk,v 1.1.1.1 2011/11/08 15:48:08 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fceux
PKG_SUPPORTED_OPTIONS=	gd gtk2 opengl sdl x11 zlib
PKG_SUGGESTED_OPTIONS=	opengl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgd)
#PLIST.gd=           yes
.include "../../graphics/gd/buildlink3.mk"
.else
.endif

.if !empty(PKG_OPTIONS:Mgtk2)
#PLIST.gtk2=           yes
BUILDLINK_API_DEPENDS.gtk2+=   gtk2+>=2.18
.include "../../x11/gtk2/buildlink3.mk"
.else
.endif

.if !empty(PKG_OPTIONS:Mopengl)
#PLIST.opengl=           yes
.include "../../graphics/Mesa/buildlink3.mk"
.else
.endif

.if !empty(PKG_OPTIONS:Msdl)
.include "../../devel/SDL/buildlink3.mk"
.else
.endif

.if !empty(PKG_OPTIONS:Mx11)
#PLIST.x11=              yes
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt?=     build # only for configure
.include "../../x11/libXt/buildlink3.mk"
.else
.endif

.if !empty(PKG_OPTIONS:Mzlib)
BUILDLINK_API_DEPENDS.zlib+=   zlib>=1.2
.include "../../devel/zlib/buildlink3.mk"
.endif
