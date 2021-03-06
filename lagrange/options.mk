# $NetBSD: options.mk,v 1.1 2019/06/10 12:41:23 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.lagrange

PKG_SUPPORTED_OPTIONS+=	mpg123 opengl
PKG_SUGGESTED_OPTIONS+=	mpg123 opengl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmpg123)
.include "../../audio/mpg123/buildlink3.mk"
CONFIGURE_ARGS+=	-DENABLE_MPG123=ON
.else
CONFIGURE_ARGS+=	-DENABLE_MPG123=OFF
.endif

.if !empty(PKG_OPTIONS:Mopengl)
CONFIGURE_ARGS+=	-DENABLE_X11_SWRENDER=OFF
.else
CONFIGURE_ARGS+=	-DENABLE_X11_SWRENDER=ON
.endif
