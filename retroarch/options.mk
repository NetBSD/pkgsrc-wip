# $NetBSD: options.mk,v 1.1 2015/02/04 22:56:43 jmcneill Exp $

.include "../../mk/bsd.fast.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.retroarch
PKG_SUPPORTED_OPTIONS+=	sdl2 alsa ffmpeg freetype libxml2
PKG_SUGGESTED_OPTIONS+=	sdl2 ffmpeg freetype

.if !empty(MACHINE_ARCH:M*arm*)
PKG_SUPPORTED_OPTIONS+=	rpi
.endif

.if !empty(MACHINE_PLATFORM:MLinux-*-arm*)
PKG_SUPPORTED_OPTIONS+=	sunxi-mali-fb
.endif

.if !empty(MACHINE_PLATFORM:MNetBSD-*-arm*)
PKG_SUGGESTED_OPTIONS+=	rpi
.endif

PKG_SUGGESTED_OPTIONS.Linux+=	alsa

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mrpi)
.include "../../misc/raspberrypi-userland/buildlink3.mk"
SUBST_CLASSES+=		vc
SUBST_STAGE.vc=		pre-configure
SUBST_MESSAGE.vc=	Fixing path to VideoCore libraries.
SUBST_FILES.vc=		qb/config.libs.sh
SUBST_SED.vc+=		-e 's;/opt/vc;${PREFIX};g'
CONFIGURE_ARGS+=	--enable-opengles
CONFIGURE_ARGS+=	--disable-opengl
.endif

#
# Enable use of the Linux binary Mali GPU driver (framebuffer version)
#
.if !empty(PKG_OPTIONS:Msunxi-mali-fb)
.include "../../wip/sunxi-mali-fb/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-floathard
CONFIGURE_ARGS+=	--enable-neon
CONFIGURE_ARGS+=	--enable-opengles
CONFIGURE_ARGS+=	--enable-mali_fbdev
CONFIGURE_ARGS+=	--disable-opengl
.endif

#
# Legacy shader support
#
.if !empty(PKG_OPTIONS:Mlibxml2)
CONFIGURE_ARGS+=	--enable-libxml2
.include "../../textproc/libxml2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-libxml2
.endif

.if !empty(PKG_OPTIONS:Msdl2)
CONFIGURE_ARGS+=	--enable-sdl2
.include "../../devel/SDL2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-sdl2
.endif

.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--enable-alsa
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-alsa
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
