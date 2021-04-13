# $NetBSD: Makefile,v 1.92 2019/04/23 09:51:47 wiz Exp $

# 2019-07-02		Bump version to 2.4.99
# COMMIT_ID=		b2103fa3257daa6acfdc6f4d4d8565abebaec4a8

# 2019-05-16		amdgpu: Add amdgpu_cs_syncobj_transfer to amdgpu-symbol-check
# COMMIT_ID=		922d92994267743266024ecceb734ce0ebbca808

# PORTNAME=		drm

# DISTNAME=		${PORTNAME}-${COMMIT_ID}
# PKGNAME=		libdrm-2.4.98
# PKGREVISION=	2
# CATEGORIES=		x11 graphics
# MASTER_SITES=		http://cgit.freedesktop.org/mesa/${PORTNAME}/snapshot/
# EXTRACT_SUFX=		.tar.xz

DISTNAME=		libdrm-2.4.99
CATEGORIES=		x11 graphics
MASTER_SITES=		http://dri.freedesktop.org/libdrm/
EXTRACT_SUFX=		.tar.bz2

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
