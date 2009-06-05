# $NetBSD: options.mk,v 1.1 2009/06/05 16:52:26 jihbed Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.lives
PKG_SUPPORTED_OPTIONS=	glib2 sdl jack mjpegtools libvisual liboil frei0r ldvgrab osc
PKG_SUGGESTED_OPTIONS=	glib2 jack mjpegtools liboil sdl

.include "../../mk/bsd.options.mk"

# Glib2 Support
.if !empty(PKG_OPTIONS:Mglib2)
.  include "../../devel/glib2/buildlink3.mk"
CONFIGURE_ARGS+=	--disable-glib-slice-allocator
.endif

# JACK support
.if !empty(PKG_OPTIONS:Mjack)
.  include "../../audio/jack/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-jack
CONFIGURE_ARGS+=	--disable-jack-transport
CONFIGURE_ARGS+=	--disable-vjack
.endif

#  mjpegtools support
.if !empty(PKG_OPTIONS:Mmjpegtools)
.  include "../../multimedia/mjpegtools/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-mjpegtools
.endif

# liboil support
.if !empty(PKG_OPTIONS:Mliboil)
.  include "../../devel/liboil/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-liboil
.endif

# libvisual support
.if !empty(PKG_OPTIONS:Mlibvisual)
.  include "../../audio/libvisual/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-libvisual
.endif

# sdl support
.if !empty(PKG_OPTIONS:Msdl)
.  include "../../devel/SDL/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-sdl
.endif

# frei0r support
.if !empty(PKG_OPTIONS:Mfrei0r)
CONFIGURE_ARGS+=	--disable-frei0r
.endif

# ldvgrab support
.if !empty(PKG_OPTIONS:Mldvgrab)
CONFIGURE_ARGS+=	--disable-ldvgrab
.endif


# osc support
.if !empty(PKG_OPTIONS:Mosc)
CONFIGURE_ARGS+=	--disable-ldvgrab
.endif
