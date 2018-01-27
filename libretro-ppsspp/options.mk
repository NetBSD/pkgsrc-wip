# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.libretro-ppsspp
PKG_OPTIONS_REQUIRED_GROUPS=	graphics
PKG_OPTIONS_GROUP.graphics=	opengl

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(MACHINE_ARCH:M*arm*)
PKG_OPTIONS_GROUP.graphics+=	rpi
PKG_SUPPORTED_OPTIONS+=		simd
.endif

.if !empty(MACHINE_ARCH:M*armv6*) || !empty(MACHINE_ARCH:M*armv7*)
PKG_SUGGESTED_OPTIONS+=		simd
.endif

.if !empty(MACHINE_PLATFORM:MLinux-*-arm*)
PKG_OPTIONS_GROUP.graphics+=	sunxi-mali-fb
.endif

.if !empty(MACHINE_PLATFORM:MNetBSD-*-arm*)
PKG_SUGGESTED_OPTIONS+=		rpi
.else
PKG_SUGGESTED_OPTIONS+=		opengl
.endif

.include "../../mk/bsd.options.mk"

#
# Enable use of the Linux binary Mali GPU driver (framebuffer version)
#
.if !empty(PKG_OPTIONS:Msunxi-mali-fb)
.include "../../wip/sunxi-mali-fb/buildlink3.mk"
BUILD_MAKE_FLAGS+=	GLES=1
BUILD_MAKE_FLAGS+=	GL_LIB=-lGLESv2
.endif

.if !empty(PKG_OPTIONS:Mopengl)
.include "../../graphics/MesaLib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msimd)
CFLAGS+=		-mfpu=neon -D__NEON_OPT
BUILD_MAKE_FLAGS+=	HAVE_NEON=1
.endif

.if !empty(PKG_OPTIONS:Mrpi)
BUILD_MAKE_FLAGS+=	platform=rpi
SUBST_CLASSES+=         vc
SUBST_STAGE.vc=         pre-configure
SUBST_MESSAGE.vc=       Fixing path to VideoCore libraries.
SUBST_FILES.vc=         libretro/Makefile
SUBST_SED.vc+=          -e 's;/opt/vc;${PREFIX};g'
.include "../../misc/raspberrypi-userland/buildlink3.mk"
.endif
