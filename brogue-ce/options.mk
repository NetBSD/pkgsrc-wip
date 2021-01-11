# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.brogue-ce

PKG_SUPPORTED_OPTIONS=	sdl2
PKG_SUGGESTED_OPTIONS=	sdl2

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

PLIST_VARS+=		sdl2

###
### SDL2 support
###
.if !empty(PKG_OPTIONS:Msdl2)
INSTALL_ASSETS=		${INSTALL_DATA}
INSTALLATION_DIRS+=	share/brogue-ce/assets
MAKE_FLAGS+=		GRAPHICS=YES
PLIST.sdl2=		yes
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.else
INSTALL_ASSETS=		${TRUE}
MAKE_FLAGS+=		GRAPHICS=NO
.endif
