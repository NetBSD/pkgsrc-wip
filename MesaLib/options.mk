# $NetBSD: options.mk,v 1.16 2015/03/03 19:50:54 tnn2 Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.MesaLib
PKG_SUPPORTED_OPTIONS=		llvm
PKG_SUGGESTED_OPTIONS=		llvm

.include "../../mk/bsd.options.mk"

# gallium
PLIST_VARS+=		swrast svga ilo i915 i965 r300 r600 radeonsi
# classic DRI
PLIST_VARS+=		swrast_dri i915_dri nouveau_dri i965_dri radeon_dri r200_dri

DRI_DRIVERS=		#
PLIST.swrast_dri=	yes
DRI_DRIVERS+=		swrast

# Software rasterizer
GALLIUM_DRIVERS=	#
PLIST.swrast+=		yes
GALLIUM_DRIVERS+=	swrast

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
# svga / VMWare driver
PLIST.svga=		yes
GALLIUM_DRIVERS+=	svga

# Intel chipsets, x86 only
PLIST.i915=		yes
GALLIUM_DRIVERS+=	i915
PLIST.i915_dri=		yes
DRI_DRIVERS+=		i915

# Experimental Intel driver
PLIST.ilo=		yes
GALLIUM_DRIVERS+=	ilo

PLIST.i965_dri=		yes
DRI_DRIVERS+=		i965
.endif

# AMD Radeon r600
PLIST.r600=		yes
GALLIUM_DRIVERS+=	r600

# Qualcomm SnapDragon, libdrm_freedreno.pc
# GALLIUM_DRIVERS+=	freedreno

# Broadcom VideoCore 4
# GALLIUM_DRIVERS+=	vc4

# nVidia, doesn't currently build
# GALLIUM_DRIVERS+=	nouveau

# classic DRI radeon
PLIST.radeon_dri=	yes
DRI_DRIVERS+=		radeon

# classic DRI r200
PLIST.r200_dri=		yes
DRI_DRIVERS+=		r200

# classic DRI nouveau
PLIST.nouveau_dri=	yes
DRI_DRIVERS+=		nouveau

CONFIGURE_ARGS+=	--with-egl-platforms=x11,drm
CONFIGURE_ARGS+=	--with-gallium-drivers=${GALLIUM_DRIVERS:ts,}
CONFIGURE_ARGS+=	--with-dri-drivers=${DRI_DRIVERS:ts,}

.if !empty(PKG_OPTIONS:Mllvm)
# AMD Radeon r300
PLIST.r300=		yes
GALLIUM_DRIVERS+=	r300
# AMD Canary Islands GPUs
PLIST.radeonsi=		yes
GALLIUM_DRIVERS+=	radeonsi
CONFIGURE_ARGS+=	--enable-gallium-llvm
CONFIGURE_ARGS+=	--enable-r600-llvm-compiler
# XXX: for libLLVM. You should turn the shlib PKG_OPTION on for now.
DEPENDS+=		clang>=3.6.0:../../lang/clang
.include "../../lang/clang/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gallium-llvm
CONFIGURE_ARGS+=	--disable-r600-llvm-compiler
.endif
