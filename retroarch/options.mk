# $NetBSD: options.mk,v 1.1 2015/02/04 22:56:43 jmcneill Exp $

.include "../../mk/bsd.fast.prefs.mk"

PKG_OPTIONS_VAR=		PKG_OPTIONS.retroarch
PKG_SUPPORTED_OPTIONS+=		sdl2 ffmpeg freetype x11 alsa caca pulseaudio udev
PKG_SUGGESTED_OPTIONS+=		sdl2 ffmpeg freetype x11
PKG_SUGGESTED_OPTIONS.Linux+=	alsa udev
PKG_OPTIONS_OPTIONAL_GROUPS+=	gl
PKG_OPTIONS_GROUP.gl+=		opengl

.if !empty(MACHINE_ARCH:M*arm*)
CONFIGURE_ARGS+=		--enable-floathard
PKG_OPTIONS_GROUP.gl+=		rpi
PKG_SUPPORTED_OPTIONS+=		simd
.endif

.if !empty(MACHINE_ARCH:M*armv7*)
PKG_SUGGESTED_OPTIONS+=		simd
.endif

.if !empty(MACHINE_PLATFORM:MLinux-*-*armv7*)
PKG_OPTIONS_GROUP.gl+=		sunxi-mali-fb
PKG_SUPPORTED_OPTIONS+=		sunxi-g2d
PKG_SUGGESTED_OPTIONS+=		sunxi-g2d
.endif

.if !empty(MACHINE_PLATFORM:MNetBSD-*-arm*)
PKG_SUGGESTED_OPTIONS+=		rpi
.else
PKG_SUGGESTED_OPTIONS+=		opengl
.endif

.include "../../mk/bsd.options.mk"

.if !empty(MACHINE_ARCH:M*arm*)
.  if !empty(PKG_OPTIONS:Msimd)
CONFIGURE_ARGS+=	--enable-neon
.  else
CONFIGURE_ARGS+=	--disable-neon
.  endif
.endif

.if !empty(PKG_OPTIONS:Mopengl)
CONFIGURE_ARGS+=	--enable-opengl
.include "../../graphics/MesaLib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-opengl
.endif

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--enable-x11
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-x11
.endif

.if !empty(PKG_OPTIONS:Mcaca)
CONFIGURE_ARGS+=	--enable-caca
.include "../../graphics/libcaca/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-caca
.endif

.if !empty(PKG_OPTIONS:Mrpi)
.include "../../misc/raspberrypi-userland/buildlink3.mk"
SUBST_CLASSES+=		vc
SUBST_STAGE.vc=		pre-configure
SUBST_MESSAGE.vc=	Fixing path to VideoCore libraries.
SUBST_FILES.vc=		qb/config.libs.sh
SUBST_SED.vc+=		-e 's;/opt/vc;${PREFIX};g'
CONFIGURE_ARGS+=	--enable-opengles
.endif

#
# Enable use of the blobless unaccelerated Linux sunxi g2d driver
#
.if !empty(PKG_OPTIONS:Msunxi-g2d)
CONFIGURE_ARGS+=	--enable-sunxi
.endif

#
# Enable use of the Linux binary Mali GPU driver (framebuffer version)
#
.if !empty(PKG_OPTIONS:Msunxi-mali-fb)
.include "../../wip/sunxi-mali-fb/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-opengles
CONFIGURE_ARGS+=	--enable-mali_fbdev
.endif

.if !empty(PKG_OPTIONS:Mudev)
# To support keyboard callback interface in udev, the libxkbcommon package
# (version 0.3 and up) is required. It is used to translate raw evdev events
# to printable characters. It does not depend on Xorg, but it depends on X11
# keyboard layout files being installed.
.include "../../x11/libxkbcommon/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-udev
.endif

.if !empty(PKG_OPTIONS:Msdl2)
CONFIGURE_ARGS+=	--enable-sdl2
.include "../../devel/SDL2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-sdl2
.endif

.if !empty(PKG_OPTIONS:Mffmpeg)
CONFIGURE_ARGS+=	--enable-ffmpeg
.include "../../multimedia/ffmpeg3/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ffmpeg
.endif

.if !empty(PKG_OPTIONS:Mfreetype)
CONFIGURE_ARGS+=	--enable-freetype
.include "../../graphics/freetype2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-freetype
.endif

.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--enable-alsa
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-alsa
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CONFIGURE_ARGS+=	--enable-pulse
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pulse
.endif
