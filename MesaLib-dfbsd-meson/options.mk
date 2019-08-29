# $NetBSD: options.mk,v 1.12 2019/04/11 16:27:03 maya Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.MesaLib
PKG_SUPPORTED_OPTIONS=		llvm dri
PKG_SUGGESTED_OPTIONS=

PKG_SUPPORTED_OPTIONS+=		glx-tls xvmc debug
PKG_SUPPORTED_OPTIONS+=		vdpau vaapi
PKG_SUPPORTED_OPTIONS+=		osmesa
PKG_SUPPORTED_OPTIONS+=		glesv1 glesv2
PKG_SUPPORTED_OPTIONS+=		xa
PKG_SUPPORTED_OPTIONS+=		asm
PKG_SUPPORTED_OPTIONS+=		noatexit
PKG_SUPPORTED_OPTIONS+=		iris
PKG_SUGGESTED_OPTIONS+=		iris
PKG_SUPPORTED_OPTIONS+=		vulkan

PKG_SUPPORTED_OPTIONS+=		test_dri3_enable
PKG_SUPPORTED_OPTIONS+=		no_render_node
PKG_SUPPORTED_OPTIONS+=		use_clock_nanosleep_os_time
PKG_SUPPORTED_OPTIONS+=		use_pthread_getcpuclockid

PKG_SUPPORTED_OPTIONS+=		revert_i965_softpin
PKG_SUPPORTED_OPTIONS+=		revert_sdma_uploader
PKG_SUPPORTED_OPTIONS+=		require_36_gen4

PKG_SUPPORTED_OPTIONS+=		physmem_netbsd
PKG_SUPPORTED_OPTIONS+=		setaffinity_np_netbsd
PKG_SUPPORTED_OPTIONS+=		no_initial_exec_nonnull

PKG_SUPPORTED_OPTIONS+=		no_cs_queue
PKG_SUPPORTED_OPTIONS+=		revert_threaded_context
PKG_SUPPORTED_OPTIONS+=		revert_copy_clear

PKG_SUPPORTED_OPTIONS+=		no_getprogramname
PKG_SUPPORTED_OPTIONS+=		strict_xsrc_netbsd

PKG_SUPPORTED_OPTIONS+=		x86_tsd_openbsd
PKG_SUPPORTED_OPTIONS+=		no_linear_alloc_destructor

PKG_SUGGESTED_OPTIONS+=		xvmc
PKG_SUGGESTED_OPTIONS+=		vdpau vaapi

PKG_SUGGESTED_OPTIONS+=		osmesa

# glesv1 and glesv2 build error on NetBSD
# due to no table_noop_array for tls patch
.if ${OPSYS} != "NetBSD"
PKG_SUGGESTED_OPTIONS+=		glesv1 glesv2
.endif

PKG_SUGGESTED_OPTIONS+=		xa

PKG_SUGGESTED_OPTIONS+=		asm

# .if ${OPSYS} == "NetBSD"
# PKG_SUGGESTED_OPTIONS+=		noatexit
# .endif

# The LLVM option enables JIT accelerated software rendering and
# is also required to support the latest RADEON GPUs, so enable it
# by default on platforms where such GPUs might be encountered.
.if (${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64") && \
	${OPSYS} != "SunOS" && ${OPSYS} != "Darwin" && \
	!(${OPSYS} == "NetBSD" && ${X11_TYPE} == "native")
PKG_SUGGESTED_OPTIONS+=		llvm
.endif

.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD" ||		\
	${OPSYS} == "DragonFly" || ${OPSYS} == "Linux" ||	\
	${OPSYS} == "SunOS" || ${OPSYS} == "Darwin" ||		\
	(${OPSYS} == "NetBSD" && ${X11_TYPE} == "modular")
PKG_SUGGESTED_OPTIONS+=		dri
.endif

# Use Thread Local Storage in GLX where it is supported by Mesa and works.
.if \
	!empty(MACHINE_PLATFORM:MNetBSD-[789].*-i386) ||	\
	!empty(MACHINE_PLATFORM:MNetBSD-[789].*-x86_64) ||	\
	!empty(MACHINE_PLATFORM:MLinux-*-i386) ||		\
	!empty(MACHINE_PLATFORM:MLinux-*-x86_64) ||		\
	!empty(MACHINE_PLATFORM:MFreeBSD-1[0-9].*-x86_64) ||	\
	!empty(MACHINE_PLATFORM:MDragonFly-*-x86_64)
PKG_SUGGESTED_OPTIONS+=		glx-tls
.endif

.if ${OPSYS} == "DragonFly" || ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=		test_dri3_enable
.endif

# Revert patch removing support for no dedicated render nodes
.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly" || ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=		no_render_node
.endif

# Use clock_nanosleep() in os_time.c
.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly" || ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=		use_clock_nanosleep_os_time
.endif

# pthread_getcpuclockid only in NetBSD 8+
.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly" || ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=		use_pthread_getcpuclockid
.endif

.if ${OPSYS} == "DragonFly"
PKG_SUGGESTED_OPTIONS+=		revert_i965_softpin
PKG_SUGGESTED_OPTIONS+=		revert_sdma_uploader
.endif

# Require Linux 3.6+ intel support for ge4+
.if ${OPSYS} == "FreeBSD"
PKG_SUGGESTED_OPTIONS+=		require_36_gen4
.endif

.if ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=		physmem_netbsd
.endif

.if ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=		setaffinity_np_netbsd
.endif

.if ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=		no_initial_exec_nonnull
.endif

.if ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=		no_cs_queue
PKG_SUGGESTED_OPTIONS+=		revert_threaded_context
PKG_SUGGESTED_OPTIONS+=		revert_copy_clear
.endif

# .if ${OPSYS} == "NetBSD"
# PKG_SUGGESTED_OPTIONS+=		no_getprogramname
# .endif

# .if ${OPSYS} == "NetBSD"
# PKG_SUGGESTED_OPTIONS+=		strict_xsrc_netbsd
# .endif

# OpenBSD xenocara tsd dispatch assembly for entry_x86_tsd.h
.if ${OPSYS} == "OpenBSD"
PKG_SUGGESTED_OPTIONS+=		x86_tsd_openbsd
.endif

.if ${OPSYS} == "OpenBSD"
PKG_SUGGESTED_OPTIONS+=		no_linear_alloc_destructor
.endif

.include "../../mk/bsd.options.mk"

# gallium
PLIST_VARS+=	freedreno i915 i965 nouveau r300 r600 radeonsi	\
		swrast svga vc4 virgl vulkan iris
# classic DRI
PLIST_VARS+=	dri swrast_dri nouveau_dri radeon_dri r200
# other features
PLIST_VARS+=	egl gbm vaapi vdpau wayland xatracker
PLIST_VARS+=	osmesa xvmc
PLIST_VARS+=	glesv1 glesv2

.if !empty(PKG_OPTIONS:Mdri)

CONFIGURE_ARGS+=	--enable-dri

# Having DRI3 and egl compiled in by default doesn't hurt, the X server
# will only use it if it is supported at run time.
CONFIGURE_ARGS+=	--enable-dri3
MESON_ARGS+=		-Ddri3=true
.  if ${OPSYS} != "Darwin"
CONFIGURE_ARGS+=	--enable-egl
CONFIGURE_ARGS+=	--enable-gbm
MESON_ARGS+=		-Degl=true
MESON_ARGS+=		-Dgbm=true
PLIST.egl=		yes
PLIST.gbm=		yes
.  else
CONFIGURE_ARGS+=	--disable-egl
CONFIGURE_ARGS+=	--disable-gbm
MESON_ARGS+=		-Degl=false
MESON_ARGS+=		-Dgbm=false
.  endif

.  if !empty(PKG_OPTIONS:Mosmesa)
CONFIGURE_ARGS+=	--enable-osmesa
MESON_ARGS+=		-Dosmesa=gallium
PLIST.osmesa=		yes
.  endif

.  if !empty(PKG_OPTIONS:Mglesv1)
CONFIGURE_ARGS+=	--enable-gles1
MESON_ARGS+=		-Dgles1=true
PLIST.glesv1=		yes
.  else
CONFIGURE_ARGS+=	--disable-gles1
MESON_ARGS+=		-Dgles1=false
.  endif

.  if !empty(PKG_OPTIONS:Mglesv2)
CONFIGURE_ARGS+=	--enable-gles2
MESON_ARGS+=		-Dgles2=true
PLIST.glesv2=		yes
.  else
CONFIGURE_ARGS+=	--disable-gles2
MESON_ARGS+=		-Dgles2=false
.  endif

.  if !empty(PKG_OPTIONS:Mglx-tls)
# Recommended by
# http://www.freedesktop.org/wiki/Software/Glamor/
CONFIGURE_ARGS+=	--enable-glx-tls
MESON_ARGS+=		-Dglx-tls=true
.  else
# (EE) Failed to load /usr/pkg/lib/xorg/modules/extensions/libglx.so:
# /usr/pkg/lib/libGL.so.1: Use of initialized Thread Local Storage with model
# initial-exec and dlopen is not supported
CONFIGURE_ARGS+=	--disable-glx-tls
MESON_ARGS+=		-Dglx-tls=false
.  endif # glx-tls

# DRI on Linux needs either sysfs or udev
CONFIGURE_ARGS.Linux+=	--enable-sysfs

PLIST.dri=	yes

.  if ${OPSYS} != "Darwin"
BUILDLINK_DEPMETHOD.libpciaccess=	full
.include "../../sysutils/libpciaccess/buildlink3.mk"
.  endif
.include "../../graphics/MesaLib/dri.mk"

DRI_DRIVERS=		#
GALLIUM_DRIVERS=	#
VULKAN_DRIVERS=		#

# Software rasterizer
# From meson.build
# if with_dri_swrast and (with_gallium_softpipe or with_gallium_swr)
#   error('Only one swrast provider can be built')
# endif
PLIST.swrast_dri=	yes
.  if ${OPSYS} != "Darwin"
PLIST.swrast=		yes
GALLIUM_DRIVERS+=	swrast
.  else
DRI_DRIVERS+=		swrast
.  endif

# x86 only drivers
.  if (${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64") && ${OPSYS} != "Darwin"
# svga / VMWare driver
PLIST.svga=		yes
GALLIUM_DRIVERS+=	svga

# Intel chipsets, x86 only
# From meson.build:
# if with_dri_i915 and with_gallium_i915
#   error('Only one i915 provider can be built')
# endif
PLIST.i915=		yes
# GALLIUM_DRIVERS+=	i915
DRI_DRIVERS+=		i915

PLIST.i965=		yes
DRI_DRIVERS+=		i965

.  endif

# Intel Iris support
.  if !empty(PKG_OPTIONS:Miris)
GALLIUM_DRIVERS+=	iris
PLIST.iris=		yes
.  endif

# Vulkan support
.  if !empty(PKG_OPTIONS:Mvulkan)
# VULKAN_DRIVERS+=	intel
# VULKAN_DRIVERS+=	radeon
VULKAN_DRIVERS+=	auto
PLIST.vulkan=		yes
.  endif

# ARM drivers
.  if !empty(MACHINE_PLATFORM:MNetBSD-*-*arm*)
# Qualcomm SnapDragon, libdrm_freedreno.pc
#GALLIUM_DRIVERS+=	freedreno
#PLIST.freedreno=	yes

# Broadcom VideoCore 4
GALLIUM_DRIVERS+=	vc4
PLIST.vc4=		yes
.  endif

# qemu Linux guest driver
.  if !empty(MACHINE_PLATFORM:MLinux-*-x86_64)
# XXX test this
#GALLIUM_DRIVERS+=	virgl
#PLIST.virgl=		yes
.  endif

# theoretically cross platform PCI drivers
.  if ${OPSYS} != "Darwin" && empty(MACHINE_PLATFORM:MNetBSD-*-*arm*) && \
	empty(MACHINE_PLATFORM:MNetBSD-*-mipsel)

# AMD Radeon r600
PLIST.r600=		yes
GALLIUM_DRIVERS+=	r600

# FULL_OS_VERSION_CMD=	${UNAME} -r
# FULL_OS_VERSION=	${FULL_OS_VERSION_CMD:sh}

# FreeBSD lacks nouveau support (there are official binaries from Nvidia)
.    if ${OPSYS} != "FreeBSD"
# nVidia
PLIST.nouveau=		yes
GALLIUM_DRIVERS+=	nouveau
.    endif

# Meson build does not compile these correctly anymore.
# classic DRI radeon
# PLIST.radeon_dri=	yes
# DRI_DRIVERS+=		radeon

# classic DRI r200
PLIST.r200=		yes
DRI_DRIVERS+=		r200

# FreeBSD lacks nouveau support (there are official binaries from Nvidia)
.    if ${OPSYS} != "FreeBSD"
# classic DRI nouveau
PLIST.nouveau_dri=	yes
DRI_DRIVERS+=		nouveau
.    endif
.  endif # cross platform PCI drivers

.  if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--with-platforms=x11
MESON_ARGS+=		-Dplatforms=x11
#.elif ${OPSYS} == "Linux"
#.include "../../devel/wayland/buildlink3.mk"
#CONFIGURE_ARGS+=	--with-platforms=x11,drm,wayland
#PLIST.wayland=		yes
.  else
CONFIGURE_ARGS+=	--with-platforms=x11,drm
MESON_ARGS+=		-Dplatforms=x11,drm
.  endif

.  if !empty(PKG_OPTIONS:Mllvm)
# VA-API and VDPAU
.    if !empty(PKG_OPTIONS:Mvaapi)
.include "../../multimedia/libva/available.mk"
.      if ${VAAPI_AVAILABLE} == "yes"
PLIST.vaapi=	yes
.include "../../multimedia/libva/buildlink3.mk"
MESON_ARGS+=	-Dgallium-va=true
.      else
MESON_ARGS+=	-Dgallium-va=false
.      endif
.    endif # vaapi
.    if !empty(PKG_OPTIONS:Mvdpau)
.include "../../multimedia/libvdpau/available.mk"
.      if ${VDPAU_AVAILABLE} == "yes"
PLIST.vdpau=	yes
.include "../../multimedia/libvdpau/buildlink3.mk"
MESON_ARGS+=	-Dgallium-vdpau=true
.      else
MESON_ARGS+=	-Dgallium-vdpau=false
.      endif
.    endif # vdpau

# XA is useful for accelerating xf86-video-vmware
.    if !empty(PKG_OPTIONS:Mxa)
CONFIGURE_ARGS+=	--enable-xa
MESON_ARGS+=		-Dgallium-xa=true
PLIST.xatracker=	yes
.    else
MESON_ARGS+=		-Dgallium-xa=false
.    endif

# AMD Radeon r300
PLIST.r300=		yes
GALLIUM_DRIVERS+=	r300
# AMD Canary Islands GPUs
PLIST.radeonsi=		yes
GALLIUM_DRIVERS+=	radeonsi
CONFIGURE_ARGS+=	--enable-llvm
CONFIGURE_ARGS+=	--enable-llvm-shared-libs
MESON_ARGS+=		-Dllvm=true
MESON_ARGS+=		-Dshared-llvm=true

.    if !exists(/usr/include/libelf.h)
.include "../../devel/libelf/buildlink3.mk"
.    endif

# XXX update libLLVM to use it instead
#BUILDLINK_API_DEPENDS.libLLVM+= libLLVM>=5.0
.include "../../lang/llvm/buildlink3.mk"

# BUILDLINK_API_DEPENDS.libLLVM+= libLLVM>=4.0
# .include "../../lang/libLLVM/buildlink3.mk"
CONFIGURE_ENV+=		ac_cv_path_ac_pt_LLVM_CONFIG=${LLVM_CONFIG_PATH}
.  else # !llvm
CONFIGURE_ARGS+=	--disable-xa
CONFIGURE_ARGS+=	--disable-llvm
CONFIGURE_ARGS+=	--disable-llvm-shared-libs
MESON_ARGS+=		-Dgallium-xa=false
MESON_ARGS+=		-Dllvm=false
MESON_ARGS+=		-Dshared-llvm=false
.  endif # llvm

CONFIGURE_ARGS+=	--with-gallium-drivers=${GALLIUM_DRIVERS:ts,}
CONFIGURE_ARGS+=	--with-dri-drivers=${DRI_DRIVERS:ts,}
CONFIGURE_ARGS+=	--with-vulkan-drivers=${VULKAN_DRIVERS:ts,}
MESON_ARGS+=		-Dgallium-drivers=${GALLIUM_DRIVERS:ts,}
MESON_ARGS+=		-Ddri-drivers=${DRI_DRIVERS:ts,}
MESON_ARGS+=		-Dvulkan-drivers=${VULKAN_DRIVERS:ts,}

.else # !dri
CONFIGURE_ARGS+=	--with-gallium-drivers=
CONFIGURE_ARGS+=	--with-dri-drivers=
CONFIGURE_ARGS+=	--with-vulkan-drivers=
CONFIGURE_ARGS+=	--disable-dri
CONFIGURE_ARGS+=	--disable-dri3
CONFIGURE_ARGS+=	--disable-egl
CONFIGURE_ARGS+=	--disable-gbm
CONFIGURE_ARGS+=	--disable-gles1
CONFIGURE_ARGS+=	--disable-gles2
CONFIGURE_ARGS+=	--enable-xlib-glx
CONFIGURE_ARGS+=	--with-platforms=x11
MESON_ARGS+=		-Dgallium-drivers=
MESON_ARGS+=		-Ddri-drivers=
MESON_ARGS+=		-Ddri3=false
MESON_ARGS+=		-Degl=false
MESON_ARGS+=		-Dgbm=false
MESON_ARGS+=		-Dgles1=false
MESON_ARGS+=		-Dgles2=false
MESON_ARGS+=		-Dglx=xlib
MESON_ARGS+=		-Dplatforms=x11
.  if !empty(PKG_OPTIONS:Mllvm)
PKG_FAIL_REASON+=	"The llvm PKG_OPTION must also be disabled when dri is disabled"
.  endif
.endif # dri

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
MESON_ARGS+=		--buildtype=debug
.endif

.if !empty(PKG_OPTIONS:Masm)
.else
MESON_ARGS+=		-Dasm=false
.endif

.if !empty(PKG_OPTIONS:Mxvmc)
.include "../../x11/libXvMC/buildlink3.mk"
PLIST.xvmc=		yes
MESON_ARGS+=		-Dgallium-xvmc=true
.else
MESON_ARGS+=		-Dgallium-xvmc=false
.endif

.if !empty(PKG_OPTIONS:Mnoatexit)
CPPFLAGS+=	-DHAVE_NOATEXIT
.endif

.if !empty(PKG_OPTIONS:Mtest_dri3_enable)
CPPFLAGS+=	-DTEST_DRI3_ENABLE
.endif

.if !empty(PKG_OPTIONS:Mno_render_node)
CPPFLAGS+=	-DNO_RENDER_NODE
.endif

.if !empty(PKG_OPTIONS:Muse_clock_nanosleep_os_time)
CPPFLAGS+=	-DUSE_CLOCK_NANOSLEEP_OS_TIME
.endif

.if !empty(PKG_OPTIONS:Muse_pthread_getcpuclockid)
CPPFLAGS+=	-DUSE_PTHREAD_GETCPUCLOCKID
.endif

.if !empty(PKG_OPTIONS:Mrevert_i965_softpin)
CPPFLAGS+=	-DREVERT_I965_SOFTPIN
.endif

.if !empty(PKG_OPTIONS:Mrevert_sdma_uploader)
CPPFLAGS+=	-DREVERT_SDMA_UPLOADER
.endif

.if !empty(PKG_OPTIONS:Mrequire_36_gen4)
CPPFLAGS+=	-DREQUIRE_36_GEN4
.endif

.if !empty(PKG_OPTIONS:Mphysmem_netbsd)
CPPFLAGS+=	-DPHYSMEM_NETBSD
.endif

.if !empty(PKG_OPTIONS:Msetaffinity_np_netbsd)
CPPFLAGS+=	-DSETAFFINITY_NP_NETBSD
.endif

.if !empty(PKG_OPTIONS:Mno_initial_exec_nonnull)
CPPFLAGS+=	-DNO_INITIAL_EXEC_NONNULL
.endif

.if !empty(PKG_OPTIONS:Mno_cs_queue)
CPPFLAGS+=	-DNO_CS_QUEUE
.endif

.if !empty(PKG_OPTIONS:Mrevert_threaded_context)
CPPFLAGS+=	-DREVERT_THREADED_CONTEXT
.endif

.if !empty(PKG_OPTIONS:Mrevert_copy_clear)
CPPFLAGS+=	-DREVERT_COPY_CLEAR
.endif

.if !empty(PKG_OPTIONS:Mno_getprogramname)
CPPFLAGS+=	-DNO_GETPROGRAMNAME
.endif

.if !empty(PKG_OPTIONS:Mstrict_xsrc_netbsd)
CPPFLAGS+=	-DSTRICT_XSRC_NETBSD
.endif

.if !empty(PKG_OPTIONS:Mx86_tsd_openbsd)
CPPFLAGS+=	-DX86_TSD_OPENBSD
.endif

.if !empty(PKG_OPTIONS:Mno_linear_alloc_destructor)
CPPFLAGS+=	-DNO_LINEAR_ALLOC_DESTRUCTOR
.endif
