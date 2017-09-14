# $NetBSD: options.mk,v 1.4 2015/02/05 21:02:37 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libretro-parallel-n64
PKG_OPTIONS_REQUIRED_GROUPS=	graphics
PKG_OPTIONS_GROUP.graphics=	opengl

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(MACHINE_ARCH:M*arm*)
PKG_OPTIONS_GROUP.graphics+=	rpi
PKG_SUPPORTED_OPTIONS+=	dynarec
PKG_SUGGESTED_OPTIONS+=	dynarec
N64_DYNAREC_ARCH=	arm
.elif !empty(MACHINE_ARCH:Mi386)
PKG_SUPPORTED_OPTIONS+=	dynarec
PKG_SUGGESTED_OPTIONS+=	dynarec opengl
N64_DYNAREC_ARCH=	x86
.elif !empty(MACHINE_ARCH:Mx86_64)
PKG_SUPPORTED_OPTIONS+=	dynarec
PKG_SUGGESTED_OPTIONS+=	dynarec opengl
N64_DYNAREC_ARCH=	x86_64
.else
PKG_SUGGESTED_OPTIONS+=	opengl
.endif

.if !empty(MACHINE_PLATFORM:MLinux-*-arm*)
PKG_OPTIONS_GROUP.graphics+=	sunxi-mali-fb
.endif

.if !empty(MACHINE_PLATFORM:MNetBSD-*-arm*)
PKG_SUGGESTED_OPTIONS+=	rpi
.endif

.include "../../mk/bsd.options.mk"

#
# Enable use of the Linux binary Mali GPU driver (framebuffer version)
#
.if !empty(PKG_OPTIONS:Msunxi-mali-fb)
.include "../../wip/sunxi-mali-fb/buildlink3.mk"
BUILD_MAKE_FLAGS+=	FORCE_GLES=1
BUILD_MAKE_FLAGS+=	HAVE_NEON=1
.endif

.if !empty(PKG_OPTIONS:Msunxi-mali-fb) || ${N64_DYNAREC_ARCH} == "arm"
CFLAGS+=		-marm
.endif

.if !empty(PKG_OPTIONS:Mopengl)
.include "../../graphics/MesaLib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mrpi)
SUBST_CLASSES+=		vc
SUBST_STAGE.vc=		pre-configure
SUBST_MESSAGE.vc=	Fixing path to VideoCore libraries.
SUBST_FILES.vc=		Makefile
SUBST_SED.vc+=		-e 's;/opt/vc;${PREFIX};g'
MAKE_ENV+=		platform=rpi
.include "../../misc/raspberrypi-userland/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mdynarec)
BUILD_MAKE_FLAGS+=	WITH_DYNAREC=${N64_DYNAREC_ARCH}
.endif
