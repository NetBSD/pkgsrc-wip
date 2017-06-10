# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.libretro-mgba

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(MACHINE_ARCH:M*armv6*) || !empty(MACHINE_ARCH:M*armv7*)
PKG_SUPPORTED_OPTIONS+=	simd
PKG_SUGGESTED_OPTIONS+=	simd
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msimd)
BUILD_MAKE_FLAGS+=	HAVE_NEON=1
.endif
