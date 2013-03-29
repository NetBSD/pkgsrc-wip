# $NetBSD: options.mk,v 1.1 2013/03/29 03:12:05 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.crabemu
PKG_SUPPORTED_OPTIONS=	bzip2 debug opengl qt sdl vdp32 zlib
PKG_SUGGESTED_OPTIONS+=	qt
PLIST_VARS+=		SDL

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mbzip2)
.include "../../archivers/bzip2/buildlink3.mk"
CMAKE_ARGS+=		-DBZip2=on
.else
CMAKE_ARGS+=		-DBZip2=off
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CMAKE_ARGS+=		-DDebug=on
.else
CMAKE_ARGS+=		-DDebug=off
.endif

.if !empty(PKG_OPTIONS:Mopengl)
.include "../../graphics/MesaLib/buildlink3.mk"
CMAKE_ARGS+=		-DOpenGL=on
.else
CMAKE_ARGS+=		-DOpenGL=off
.endif

.if !empty(PKG_OPTIONS:Mqt)
.include "../../x11/qt4-tools/buildlink3.mk"
CMAKE_ARGS+=		-DQt=on
.else
CMAKE_ARGS+=		-DQt=off
.endif

.if !empty(PKG_OPTIONS:Msdl)
.include "../../lang/lua/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
CMAKE_ARGS+=		-DSDL=on
PLIST.SDL=		yes
.else
CMAKE_ARGS+=		-DSDL=off
.endif

.if !empty(PKG_OPTIONS:Mvdp32)
CMAKE_ARGS+=		-DVDP32=on
.else
CMAKE_ARGS+=		-DVDP32=off
.endif

.if !empty(PKG_OPTIONS:Mzlib)
.include "../../devel/zlib/buildlink3.mk"
CMAKE_ARGS+=		-DZLIB=on
.else
CMAKE_ARGS+=		-DZLIB=off
.endif
