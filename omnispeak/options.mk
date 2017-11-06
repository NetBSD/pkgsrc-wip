PKG_OPTIONS_VAR=		PKG_OPTIONS.omnispeak
PKG_OPTIONS_OPTIONAL_GROUPS=	sdl
PKG_OPTIONS_GROUP.sdl=		sdl sdl2
PKG_SUGGESTED_OPTIONS=		sdl2

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

###
### SDL support
###

.if !empty(PKG_OPTIONS:Msdl)
.  include "../../devel/SDL/buildlink3.mk"
BUILD_MAKE_FLAGS+=	WITH_SDL2=0
.endif

.if !empty(PKG_OPTIONS:Msdl2)
.  include "../../devel/SDL2/buildlink3.mk"
.  include "../../mk/x11.buildlink3.mk"
BUILD_MAKE_FLAGS+=	WITH_SDL2=1
BUILD_MAKE_FLAGS+=	X11_LDFLAGS=${X11_LDFLAGS:Q}
.endif
