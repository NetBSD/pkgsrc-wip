# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.arx-libertatis

PKG_OPTIONS_REQUIRED_GROUPS=	opengl sdl
PKG_OPTIONS_GROUP.opengl=	epoxy glew
PKG_OPTIONS_GROUP.sdl=		sdl sdl2

PKG_SUGGESTED_OPTIONS=		epoxy sdl2

.include "../../mk/bsd.options.mk"

###
### OpenGL function wrangler
###
.if !empty(PKG_OPTIONS:Mepoxy)
CMAKE_ARGS+=	-D WITH_OPENGL:STRING=epoxy
.include "../../graphics/libepoxy/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mglew)
CMAKE_ARGS+=	-D WITH_OPENGL:STRING=glew
.include "../../graphics/glew/buildlink3.mk"
.endif


### SDL implementation
###
.if !empty(PKG_OPTIONS:Msdl)
CMAKE_ARGS+=	-D WITH_SDL:INT=1
.include "../../devel/SDL/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msdl2)
CMAKE_ARGS+=	-D WITH_SDL:INT=2
.include "../../devel/SDL2/buildlink3.mk"
.endif

# graphics/glew or graphics/libepoxy
