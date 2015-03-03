# $NetBSD: options.mk,v 1.14 2015/03/03 17:45:35 tnn2 Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.MesaLib
PKG_SUPPORTED_OPTIONS=		llvm
PKG_SUGGESTED_OPTIONS=		llvm

.include "../../mk/bsd.options.mk"

# Software rasterizer, always build this
GALLIUM_DRIVERS=	swrast

# svga
GALLIUM_DRIVERS+=	svga

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
# Intel chipsets, x86 only
GALLIUM_DRIVERS+=	i915

# Experimental Intel driver
GALLIUM_DRIVERS+=	ilo
.endif

# AMD Radeon r600
GALLIUM_DRIVERS+=	r600

# AMD Canary Islands GPUs, needs --with-egl-platforms=drm
# GALLIUM_DRIVERS+=	radeonsi

# Qualcomm SnapDragon, libdrm_freedreno.pc
# GALLIUM_DRIVERS+=	freedreno

# Broadcom videoCore 4
# GALLIUM_DRIVERS+=	vc4

# nVidia, doesn't currently build
# GALLIUM_DRIVERS+=	nouveau

CONFIGURE_ARGS+=	--with-gallium-drivers=${GALLIUM_DRIVERS:ts,}
.if !empty(PKG_OPTIONS:Mllvm)
GALLIUM_DRIVERS+=	r300
CONFIGURE_ARGS+=	--enable-gallium-llvm
CONFIGURE_ARGS+=	--enable-r600-llvm-compiler
# XXX: for libLLVM. You should turn the shlib PKG_OPTION on for now.
DEPENDS+=		clang>=3.6.0:../../lang/clang
.include "../../lang/clang/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gallium-llvm
CONFIGURE_ARGS+=	--disable-r600-llvm-compiler
.endif
