# $NetBSD: options.mk,v 1.2 2015/02/05 16:57:36 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libretro-pcsx-rearmed

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(MACHINE_ARCH:M*arm*)
PKG_SUPPORTED_OPTIONS+=	dynarec
PKG_SUGGESTED_OPTIONS+=	dynarec
.endif

.if !empty(MACHINE_ARCH:M*armv7*)
PKG_SUPPORTED_OPTIONS+=	simd
PKG_SUGGESTED_OPTIONS+=	simd
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdynarec)
BUILD_MAKE_FLAGS+=	DRC_CACHE_BASE=0
BUILD_MAKE_FLAGS+=	USE_DYNAREC=1
.endif

.if !empty(PKG_OPTIONS:Msimd)
CFLAGS+=		-mfpu=neon # needed for assembly code to work
BUILD_MAKE_FLAGS+=	HAVE_NEON=1
BUILD_MAKE_FLAGS+=	BUILTIN_GPU=neon
.endif
