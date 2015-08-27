# $NetBSD: options.mk,v 1.3 2015/08/27 15:19:08 anielski Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fluxbox
PKG_SUPPORTED_OPTIONS=	imlib2 xft xrender bidi
PKG_SUGGESTED_OPTIONS=	xrender xft bidi

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mimlib2)
CONFIGURE_ARGS+=	--enable-imlib2
.include "../../graphics/imlib2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-imlib2
.endif

.if !empty(PKG_OPTIONS:Mxft)
CONFIGURE_ARGS+=	--enable-xft
.include "../../x11/libXft/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-xft
.endif

.if !empty(PKG_OPTIONS:Mxrender)
CONFIGURE_ARGS+=	--enable-xrender
.include "../../x11/libXrender/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-xrender
.endif

.if !empty(PKG_OPTIONS:Mbidi)
CONFIGURE_ARGS+=        --enable-fribidi
.include "../../converters/fribidi/buildlink3.mk"
.else
CONFIGURE_ARGS+=        --disable-fribidi
.endif
