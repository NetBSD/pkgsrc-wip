# $NetBSD: Makefile,v 1.92 2019/04/23 09:51:47 wiz Exp $

# 2019-05-16		amdgpu: Add amdgpu_cs_syncobj_transfer to amdgpu-symbol-check
COMMIT_ID=		922d92994267743266024ecceb734ce0ebbca808

# 2019-05-03		xf86drm: Fix possible memory leak with drmModeGetPropertyPtr()
# COMMIT_ID=		b39377d66ac04363f3c47ba5870c5ef71a95f5b8

# 2019-04-25		tests/libkms-test-plane: fix possbile memory leak
# COMMIT_ID=		6a7d1329dbcc898f51173885db08d36c80bb5f20

# 2019-04-19		Bump the version to 2.4.98
# COMMIT_ID=		be3b07617fc999e366e8185dbc7851ae5943df27

# 2019-04-18		amdgpu: Add context priority override function.
# COMMIT_ID=		232dc3305d55d199f4765968d299bfc2a249d920

# 2019-04-17		tests/util: Add armada-drm driver
# COMMIT_ID=		0b474eab3dd37c09f7f05e55176fcaea76fb4f92

# 2019-04-12		amdgpu: Fix a structure initialization issueHEADmaster
# COMMIT_ID=		fcf80e2fd7741c9140e5e2971f9742fe7a82f68e

# 2019-04-04		drm/amdgpu: support test mask
# COMMIT_ID=		b4fbc6d70cf39971aed731ccf66246302d788899

# 2019-03-25		intel: sync i915_pciids.h with kernel
# COMMIT_ID=		ae836decb41a69d00bfadab78a7cb69f88de4c94

# 2019-03-20		tests/amdgpu: minor fix for dispatch/draw test
# COMMIT_ID=		a85b31c973d9f619be862655793ab957318321dc

# 2019-03-18		tests/amdgpu: add memcpy draw test
# COMMIT_ID=		852a9d20ad645d399774a2b3ff1746521841ba54

# 2019-03-12		xf86drm: Fix segmentation fault while parsing device info
# COMMIT_ID=		4735ca71af9f741e2438104d543dc3c5a8107f35

# 2019-02-26		configure.ac fix build error for config.h in autotools
# COMMIT_ID=		d54e546852dd6ffdc732ffa17f102b7ce87a7352

# 2019-02-01		amdgpu: add some raven marketing names
# COMMIT_ID=		6415bd3ced9d80137e30cb90837eb01932607882

PORTNAME=		drm

DISTNAME=		${PORTNAME}-${COMMIT_ID}
PKGNAME=		libdrm-2.4.98
# PKGREVISION=	2
CATEGORIES=		x11 graphics
MASTER_SITES=		http://cgit.freedesktop.org/mesa/${PORTNAME}/snapshot/
EXTRACT_SUFX=		.tar.xz


# DISTNAME=		libdrm-2.4.97
# CATEGORIES=		x11 graphics
# MASTER_SITES=		http://dri.freedesktop.org/libdrm/
# EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://dri.freedesktop.org/wiki/DRM
COMMENT=		Userspace interface to kernel DRM services

ONLY_FOR_PLATFORM=	NetBSD-*-* DragonFly-*-* FreeBSD-*-* OpenBSD-*-* \
			Linux-*-* SunOS-*-*

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
# USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	libdrm.pc.in
# GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		atomic
SUBST_FILES.atomic=	xf86drm.h
SUBST_MESSAGE.atomic=	Configuring xf86drm.h s atomic operations.
SUBST_STAGE.atomic=	pre-configure
SUBST_VARS.atomic=	ATOMIC_OPS_CHECK

ATOMIC_OPS_CHECK=	0
.if exists(${CROSS_DESTDIR}/usr/include/sys/atomic.h)
ATOMIC_OPS_CHECK=	1
.else
# Intel driver no longer needs libatomic_ops
.  if ${MACHINE_ARCH} != "i386" && ${MACHINE_ARCH} != x86_64
.    include "../../devel/libatomic_ops/buildlink3.mk"
CONFIGURE_ENV+=		drm_cv_atomic_primitives=libatomic-ops
.  endif
.endif

CONFIGURE_ARGS+=	PTHREADSTUBS_CFLAGS=-I${PREFIX}/include \
			PTHREADSTUBS_LIBS=-L${PREFIX}/lib
CONFIGURE_ARGS+=	--disable-manpages
CONFIGURE_ARGS+=	--disable-valgrind
MESON_ARGS+=		-Dman-pages=false
MESON_ARGS+=		-Dvalgrind=false

LDFLAGS.NetBSD+=	-lpci

PLIST_VARS+=	intel arm
.if !empty(MACHINE_ARCH:Mi386) || !empty(MACHINE_ARCH:Mx86_64)
# libpciaccess is needed to build support for the intel KMS API,
# libdrm_intel.so.
.include "../../sysutils/libpciaccess/buildlink3.mk"
PLIST.intel=	yes
.elif !empty(MACHINE_ARCH:Marm*) || \
      !empty(MACHINE_ARCH:Mearm*) || \
      !empty(MACHINE_ARCH:Maarch64)
PLIST.arm=	yes
#.else
#CONFIGURE_ARGS+=	--disable-intel
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.libdrm
PKG_SUPPORTED_OPTIONS=	libkms
PKG_SUGGESTED_OPTIONS=

PKG_SUPPORTED_OPTIONS+=	invert_atomic_add_unless
.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly"
PKG_SUGGESTED_OPTIONS+=	invert_atomic_add_unless
.endif

# .if !empty(MACHINE_ARCH:Mi386) || !empty(MACHINE_ARCH:Mx86_64)
# PKG_SUGGESTED_OPTIONS+=	libkms
# .endif

PKG_SUPPORTED_OPTIONS+=	strict_xsrc_netbsd
.if ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=	strict_xsrc_netbsd
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		libkms
.if !empty(PKG_OPTIONS:Mlibkms)
PKGCONFIG_OVERRIDE+=	libkms.pc.in
PLIST.libkms=		yes
CONFIGURE_ARGS+=	--enable-libkms
MESON_ARGS+=		-Dlibkms=true
.else
CONFIGURE_ARGS+=	--disable-libkms
MESON_ARGS+=		-Dlibkms=false
.endif

.if !empty(PKG_OPTIONS:Minvert_atomic_add_unless)
CPPFLAGS+=	-DINVERT_ATOMIC_ADD_UNLESS
.endif

.if !empty(PKG_OPTIONS:Mstrict_xsrc_netbsd)
CPPFLAGS+=	-DSTRICT_XSRC_NETBSD
.endif

# Meson
# CPPFLAGS+=	-Wno-return-type
.include "../../devel/meson/build.mk"

.include "../../mk/bsd.pkg.mk"
