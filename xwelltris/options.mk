# $NetBSD: options.mk,v 1.2 2008/08/09 19:47:19 leot1990 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xwelltris
PKG_SUPPORTED_OPTIONS=	sdl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=	--with-sdl
.  include "../../devel/SDL/buildlink3.mk"
.  include "../../graphics/SDL_image/buildlink3.mk"
.else
.  include "../../x11/libXext/buildlink3.mk"
.endif
