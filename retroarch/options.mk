# $NetBSD: options.mk,v 1.1 2015/02/04 22:56:43 jmcneill Exp $

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.retroarch
PKG_SUPPORTED_OPTIONS+=	sdl2 alsa ffmpeg freetype libusb-1
PKG_SUGGESTED_OPTIONS+=	sdl2 ffmpeg freetype libusb-1

.if !empty(MACHINE_ARCH:M*arm*)
PKG_SUPPORTED_OPTIONS+=	rpi
PKG_SUGGESTED_OPTIONS+=	rpi
.endif

PKG_SUGGESTED_OPTIONS.Linux+=	alsa

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mrpi)
.include "../../misc/raspberrypi-userland/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msdl2)
CONFIGURE_ARGS+=	--enable-sdl2
.include "../../devel/SDL2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-sdl2
.endif

.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=        --enable-alsa
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=        --disable-alsa
.endif

.if !empty(PKG_OPTIONS:Mffmpeg)
CONFIGURE_ARGS+=        --enable-ffmpeg
.include "../../multimedia/ffmpeg3/buildlink3.mk"
.else
CONFIGURE_ARGS+=        --disable-ffmpeg
.endif

.if !empty(PKG_OPTIONS:Mlibusb-1)
CONFIGURE_ARGS+=        --enable-libusb
.include "../../devel/libusb1/buildlink3.mk"
.else
CONFIGURE_ARGS+=        --disable-libusb
.endif

.if !empty(PKG_OPTIONS:Mfreetype)
CONFIGURE_ARGS+=        --enable-freetype
.include "../../graphics/freetype2/buildlink3.mk"
.else
CONFIGURE_ARGS+=        --disable-freetype
.endif
